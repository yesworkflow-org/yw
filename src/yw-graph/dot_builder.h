#pragma once

#include "yw_config.h"

#include <sstream>

namespace yw {
    namespace graph {

        std::stringstream dotStream;
        yw::config::Configuration configuration;

        class DotBuilder {

            static yw::config::Configuration defaults;

        public:

            static const yw::config::Configuration& getSoftwareSettings();

            DotBuilder(
                const yw::config::Configuration& userConfiguration = yw::config::Configuration{}
            );

            void beginGraph();
            void comment(std::string text);
            void endGraph();
            void quotedText(std::string unquotedText);
            void title(std::string text);
        };
    }
}