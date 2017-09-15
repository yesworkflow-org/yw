#include "dot_builder.h"

#include <regex>

using namespace yw::config;
using std::endl;
using std::string;

using Visibility = SoftwareSetting::Visibility;

namespace yw {
    namespace graph {

        yw::config::Configuration DotBuilder::defaults;

        const Configuration& DotBuilder::getSoftwareSettings() {
            if (defaults.size() == 0) {

                defaults.insert(SoftwareSetting{ "graph.layout", "TB", "Direction of graph layout", {"TB", "LR", "RL", "BT" } });
                defaults.insert(SoftwareSetting{ "graph.title", null_string, "Title for the graph as a whole" });
                defaults.insert(SoftwareSetting{ "graph.titleposition", "TOP", "Where to place graph title",{ "TOP", "BOTTOM", "HIDE" } });

                defaults.insert(SoftwareSetting{ "graph.comments", "ON", "Include comments in dot file",{ "ON", "OFF" }, Visibility::EXPERT });
            }
            return defaults;
        }

        string DotBuilder::config(const string& key) {
            return configuration.getStringValue(key);
        }

        DotBuilder::DotBuilder(
            const yw::config::Configuration& userConfiguration
        ) {
            configuration.insertAll(getSoftwareSettings());
            configuration.insertAll(userConfiguration);
        }

        void DotBuilder::beginGraph(const string& graphName) {

            dotStream << "digraph " << q(graphName) << " {" << endl;
            
            auto graphLayout = config("graph.layout");
            horizontalLayout = (graphLayout == "LR") || (graphLayout == "RL");
            if (graphLayout != "TB") {
                dotStream << "rankdir=" << graphLayout << endl;
            }

            if (configuration.getSetting("graph.title").value.hasValue()) {
                title(config("graph.title"));
            }
        }

        void DotBuilder::beginSubgraph(const std::string& name, bool visible) {

            string outer = "cluster_" + name + "_outer";
            string inner = "cluster_" + name + "_inner";

            if (visible) {
                dotStream << "subgraph " << q(outer) 
                          << " { label=" << q("") << "; color=black; penwidth=2" << endl;
            } else {
                dotStream << "subgraph " << q(outer) << " { label=" << q("") << "; penwidth=0" << endl;
            }

            dotStream << "subgraph " << q(inner) << " { label=" << q("") << "; penwidth=0" << endl;
        }

        void DotBuilder::endSubgraph() {
            dotStream << "}}" << endl;
        }

        void DotBuilder::comment(const string& text) {
            if (config("graph.comments") == "ON") {
                dotStream << endl;
                dotStream << "/* " << text << " */" << endl;
            }
        }

        void DotBuilder::edge(const string& from, const string& to, const string& label) {
            dotStream << q(from) << " -> " << q(to);
            if (!label.empty()) {
                dotStream << " [label=" << q(label) << "]";
            }
            dotStream << endl;
        }

        void DotBuilder::edge(const string& from, const string& to) {
            edge(from, to, "");
        }

        void DotBuilder::endGraph() {
            dotStream << "}" << endl;
        }

        void DotBuilder::flushEdgeStyle() {
            dotStream << "edge[fontname=" << edgeFont << "]" << endl;
        }

        void DotBuilder::flushNodeStyle() {
            dotStream << "node[shape=" << q(nodeShape)
                        << " style=" << q(nodeStyle)
                        << " fillcolor=" << q(nodeFillcolor)
                        << " peripheries=" << nodePeripheries
                        << " fontname=" << q(nodeFont);
            if (nodeWidth > 0)  dotStream << " width=" << nodeWidth;
            dotStream << "]" << endl;
        }

        void DotBuilder::node(const string& name, const string& label) {
            dotStream << q(name);
            if (label != name) {
                dotStream << " [label=" << q(label) << "]";
            }
            dotStream << endl;
        }

        void DotBuilder::node(const string& name) {
            node(name, name);
        }

        void DotBuilder::recordNode(const std::string& name, const std::string& label1, const std::string& label2) {
            dotStream << q(name) << " [shape=record rankdir=LR label=\"{";
            if (horizontalLayout) dotStream << "{";
            dotStream << "<f0> " << esc(label1) << " |<f1> " << esc(label2);
            if (horizontalLayout) dotStream << "}";
            dotStream << "}\"];" << endl;
        }


        std::regex doubleQuoteSymbolPattern{ "\"" };
        std::regex leftBracePattern{ "\\{" };
        std::regex rightBracePattern{ "\\}" }; 
        std::regex colonPattern{ ":" };
        std::regex validDotIdPattern{ "[a-zA-Z_0-9]+" };

        std::string DotBuilder::q(const string& text) {
            std::string s;
            if (std::regex_match(text, validDotIdPattern)) {
                s = text;
            }
            else {
                s = "\"" + std::regex_replace(text, doubleQuoteSymbolPattern, "\\\"") + "\"";
            }
            return s;
        }

        string DotBuilder::esc(const string& text) {
            std::string s = text;
            if (!std::regex_match(text, validDotIdPattern)) {
                s = std::regex_replace(s, leftBracePattern, "\\{");
                s = std::regex_replace(s, rightBracePattern, "\\}");
                s = std::regex_replace(s, colonPattern, "\\:");
            }
            return s;
        }

        void DotBuilder::title(const string& text) {
            auto position = configuration.getStringValue("graph.titleposition");
            if (position != "HIDE") {
                comment("Title for graph");
                dotStream << "fontname=Helvetica; fontsize=18; labelloc=";
                dotStream << ((position == "TOP") ? "t" : "b");
                dotStream << endl;
                dotStream << "label=" << q(text) << endl;
            }
        }

    }
}