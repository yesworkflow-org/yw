#pragma once

#include "command_line.h"

namespace yw {
    namespace graph {

        int cli(yw::cli::CommandLine& commandLine);
        void print_help();
    }
}