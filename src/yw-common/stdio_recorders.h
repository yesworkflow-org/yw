#pragma once

#include <iostream>
#include <sstream>

namespace yw {

    class StderrRecorder {
        std::stringstream recording;
        std::streambuf * previousBuffer;
    public:
        StderrRecorder();
        ~StderrRecorder();
        std::string str();
    };

    class StdoutRecorder {
        std::stringstream recording;
        std::streambuf * previousBuffer;
    public:
        StdoutRecorder();
        ~StdoutRecorder();
        std::string str();
    };

}