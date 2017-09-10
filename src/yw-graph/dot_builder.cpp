#include "dot_builder.h"

using namespace yw::config;
using std::endl;
using std::string;

namespace yw {
    namespace graph {

        yw::config::Configuration DotBuilder::defaults;

        const Configuration& DotBuilder::getSoftwareSettings() {
            if (defaults.size() == 0) {
                defaults.insert(SoftwareSetting{ "graph.dotcomments", "ON", "Include comments in dot file",{ "ON", "OFF" } });
                defaults.insert(SoftwareSetting{ "graph.layout", "TB", "Direction of graph layout", {"TB", "LR", "RL", "BT" } } );
                defaults.insert(SoftwareSetting{ "graph.titleposition", "TOP", "Where to place graph title",{ "TOP", "BOTTOM", "HIDE" } });
            }
            return defaults;
        }

        DotBuilder::DotBuilder(
            const yw::config::Configuration& userConfiguration
        ) {
            configuration.insertAll(getSoftwareSettings());
            configuration.insertAll(userConfiguration);
        }

        void DotBuilder::beginGraph() {
            dotStream << "digraph Workflow {" << endl;
            dotStream << "rankdir=" << configuration.getStringValue("graph.layout") << endl;
        }

        void DotBuilder::comment(string text) {
            dotStream << endl;
            dotStream << "/*" << text << "*/" << endl;
        }

        void DotBuilder::endGraph() {
            dotStream << "}" << endl;
        }

        void DotBuilder::title(string text) {
            auto position = configuration.getStringValue("graph.titleposition");
            if (position != "HIDE") {
                comment("Title for graph");
                dotStream << "fontname=Helvetica; fontsize=18; labelloc=";
                dotStream << (position == "TOP") ? "t" : "b";
                dotStream << endl;
                dotStream << "label=";
                quotedText(text);
                dotStream << endl;
            }
        }

        void DotBuilder::quotedText(string unquotedText) {
            dotStream << "\"" << unquotedText << "\"";
        }
    }
}