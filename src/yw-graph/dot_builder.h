#pragma once

#include "yw_config.h"

#include <sstream>

namespace yw {
    namespace graph {


        class DotBuilder {

            std::stringstream dotStream;
            yw::config::Configuration configuration;
            std::string edgeFont = "Helvetica";
            std::string nodeFillcolor = "#FFFFFF";
            std::string nodeFont = "Helvetica";
            size_t nodePeripheries = 1;
            std::string nodeShape = "box";
            std::string nodeStyle = "filled";
            double nodeWidth = -1;


            static yw::config::Configuration defaults;

        public:

            static const yw::config::Configuration& getSoftwareSettings();

            DotBuilder(
                const yw::config::Configuration& userConfiguration = yw::config::Configuration{}
            );

            std::string str() { return dotStream.str(); }

            void beginGraph(const std::string& graphName = "Workflow");
            void beginSubgraph(const std::string& name, bool visible);
            void comment(const std::string& text);
            void edge(const std::string& from, const std::string& to, const std::string& label);
            void edge(const std::string& from, const std::string& to);
            void endGraph();
            void endSubgraph();
            void flushEdgeStyle();
            void flushNodeStyle();
            void node(const std::string& name, const std::string& label);
            void node(const std::string& name);

            void setEdgeFont(const std::string& font) { edgeFont = font; }
            void setNodeFillcolor(const std::string& color) { nodeFillcolor = color; }
            void setNodeFont(const std::string& font) { nodeFont = font;  }
            void setNodePeripheries(size_t peripheries) { nodePeripheries = peripheries; }
            void setNodeShape(const std::string& shape) { nodeShape = shape; }
            void setNodeStyle(const std::string& style) { nodeStyle = style;  }
            void setNodeWidth(double width) { nodeWidth = width; }

        private:

            std::string config(const std::string& key);
            const std::string q(const std::string& unquotedText);
            void title(const std::string& text);
            void rankdir(const std::string& text);

        };
    }
}