#include "stdio_recorders.h"

namespace yw {

    StderrRecorder::StderrRecorder() : 
        previousBuffer{ std::cerr.rdbuf(recording.rdbuf()) } 
    {}

    StderrRecorder::~StderrRecorder() {
        std::cerr.rdbuf(previousBuffer); 
    }

    std::string StderrRecorder::str() { return recording.str(); }

    StdoutRecorder::StdoutRecorder() : 
        previousBuffer{ std::cout.rdbuf(recording.rdbuf()) } 
    {}

    StdoutRecorder::~StdoutRecorder() { 
        std::cout.rdbuf(previousBuffer); 
    }

    std::string StdoutRecorder::str() { return recording.str(); }
}