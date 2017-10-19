#include "yw_graph_cli.h"

int main(int argc, char** argv)
{
    try {
        return yw::graph::cli(yw::cli::CommandLine(argc, argv));
    }
    catch (std::exception e) {
        std::cerr << "ERROR: An unexpected exception occurred." << std::endl;
        std::cerr << "CAUSE: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "ERROR: An unexpected and unrecogized exception occurred." << std::endl;
    }
}