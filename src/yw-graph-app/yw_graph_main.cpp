#include "yw_graph_cli.h"

int main(int argc, char** argv)
{
    return yw::graph::cli(yw::cli::CommandLine(argc, argv));
}