#pragma once

#include "gvc.h"
#include "xdot.h"

#include <string>

namespace yw {
    namespace graphviz {

        class GraphvizRenderer {

        private:
            GVC_t *context;
            Agraph_t *graph;
            std::string dotText;
            std::string layoutEngine;
            std::string imageFormat;

        public:
            GraphvizRenderer(
                std::string dotText,
                std::string layoutEngine = "dot",
                std::string imageFormat = "png"
            );

            ~GraphvizRenderer();

            std::string str();
            void write(FILE *file = stdout);
        };
    }
}
