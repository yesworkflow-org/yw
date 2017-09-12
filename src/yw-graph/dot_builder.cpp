#include "dot_builder.h"

#include <regex>

using namespace yw::config;
using std::endl;
using std::string;

namespace yw {
    namespace graph {

        yw::config::Configuration DotBuilder::defaults;

        const Configuration& DotBuilder::getSoftwareSettings() {
            if (defaults.size() == 0) {
                defaults.insert(SoftwareSetting{ "graph.dotcomments", "OFF", "Include comments in dot file",{ "ON", "OFF" } });
                defaults.insert(SoftwareSetting{ "graph.layout", "TB", "Direction of graph layout", {"TB", "LR", "RL", "BT" } });
                defaults.insert(SoftwareSetting{ "graph.title", null_string, "Title for the graph as a whole" });
                defaults.insert(SoftwareSetting{ "graph.titleposition", "TOP", "Where to place graph title",{ "TOP", "BOTTOM", "HIDE" } });
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
            if (config("graph.layout") != "TB") rankdir(config("graph.layout"));
            if (configuration.getSetting("graph.title").value.hasValue()) {
                title(config("graph.title"));
            }
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

        std::regex doubleQuoteSymbolPattern{ "\"" };
        std::regex validDotIdPattern{ "[a-zA-Z_0-9]+" };

        const std::string DotBuilder::q(const string& text) {
            std::string s;
            if (std::regex_match(text, validDotIdPattern)) {
                s = text;
            }
            else {
                s = "\"" + std::regex_replace(text, doubleQuoteSymbolPattern, "\\\"") + "\"";
            }
            return s;
        }

        void DotBuilder::rankdir(const string& direction) {
            dotStream << "rankdir=" << direction << endl;
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