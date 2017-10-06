#pragma once

#include "command_line.h"

namespace yw {
    namespace graph {

        int cli(const yw::cli::CommandLine& commandLine);
        void printUsage();
    }
}