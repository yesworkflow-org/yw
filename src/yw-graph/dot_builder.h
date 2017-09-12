#pragma once

#include "yw_config.h"

#include <sstream>

namespace yw {
    namespace graph {


        class DotBuilder {

            std::stringstream dotStream;
            yw::config::Configuration configuration;

            static yw::config::Configuration defaults;

        public:

            static const yw::config::Configuration& getSoftwareSettings();

            DotBuilder(
                const yw::config::Configuration& userConfiguration = yw::config::Configuration{}
            );

            std::string str() { return dotStream.str(); }

            void beginGraph(const std::string& graphName = "Workflow");
            void comment(const std::string& text);
            void edge(const std::string& from, const std::string& to, const std::string& label);
            void edge(const std::string& from, const std::string& to);
            void endGraph();
            void node(const std::string& name, const std::string& label);
            void node(const std::string& name);

        private:

            std::string config(const std::string& key);
            const std::string q(const std::string& unquotedText);
            void title(const std::string& text);
            void rankdir(const std::string& text);

        };
    }
}