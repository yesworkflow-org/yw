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
                defaults.insert(SoftwareSetting{ "graph.layout", "TB", "Direction of graph layout", {"TB", "LR", "RL", "BT" } } );
                defaults.insert(SoftwareSetting{ "graph.title", null_string, "Title for the graph as a whole" });
                defaults.insert(SoftwareSetting{ "graph.titleposition", "TOP", "Where to place graph title",{ "TOP", "BOTTOM", "HIDE" } });
            }
            return defaults;
        }

        string DotBuilder::config(std::string key) {
            return configuration.getStringValue(key);
        }

        DotBuilder::DotBuilder(
            const yw::config::Configuration& userConfiguration
        ) {
            configuration.insertAll(getSoftwareSettings());
            configuration.insertAll(userConfiguration);
        }

        void DotBuilder::beginGraph(string graphName) {
            dotStream << "digraph ";
            quotedIfNeeded(graphName);
            dotStream << " {" << endl;
            if (config("graph.layout") != "TB") rankdir(config("graph.layout"));
            if (configuration.getSetting("graph.title").value.hasValue()) {
                title(config("graph.title"));
            }
        }

        void DotBuilder::comment(string text) {
            if (config("graph.comments") == "ON") {
                dotStream << endl;
                dotStream << "/* " << text << " */" << endl;
            }
        }

        void DotBuilder::endGraph() {
            dotStream << "}" << endl;
        }

        void DotBuilder::node(std::string name, std::string label) {
            quotedIfNeeded(name);
            if (label != name) {
                dotStream << " [label=";
                quotedIfNeeded(label);
                dotStream << "]";
            }
            dotStream << endl;
        }

        void DotBuilder::node(std::string name) {
            node(name, name);
        }

        std::regex doubleQuoteSymbolPattern{ "\"" };
        std::regex validDotIdPattern{ "[a-zA-Z_0-9]+" };

        void DotBuilder::quotedAlways(string text) {
            dotStream << "\"" << std::regex_replace(text, doubleQuoteSymbolPattern, "\\\"") << "\"";
        }


        void DotBuilder::quotedIfNeeded(string unquotedText) {
            if (std::regex_match(unquotedText, validDotIdPattern)) {
                dotStream << unquotedText;
            }
            else {
                quotedAlways(unquotedText);
            }
        }

        void DotBuilder::rankdir(string direction) {
            dotStream << "rankdir=" << direction << endl;
        }

        void DotBuilder::title(string text) {
            auto position = configuration.getStringValue("graph.titleposition");
            if (position != "HIDE") {
                comment("Title for graph");
                dotStream << "fontname=Helvetica; fontsize=18; labelloc=";
                dotStream << ((position == "TOP") ? "t" : "b");
                dotStream << endl;
                dotStream << "label=";
                quotedAlways(text);
                dotStream << endl;
            }
        }

    }
}