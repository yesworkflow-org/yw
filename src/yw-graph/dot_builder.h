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
            void quotedText(std::string unquotedText);

        private:

            std::string config(std::string key);
            void title(std::string text);
            void rankdir(std::string text);

        };
    }
}