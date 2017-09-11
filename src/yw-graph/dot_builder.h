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

            void beginGraph();
            void comment(std::string text);
            void endGraph();
            void node(std::string name, std::string label);
            void node(std::string name);

        private:

            std::string config(std::string key);
            void quotedAlways(std::string unquotedText);
            void quotedIfNeeded(std::string unquotedText);
            void title(std::string text);
            void rankdir(std::string text);

        };
    }
}