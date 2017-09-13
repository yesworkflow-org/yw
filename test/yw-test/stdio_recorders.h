#pragma once

#include <iostream>
#include <sstream>

namespace yw {
    namespace test {

        class StderrRecorder {
            std::stringstream recording;
            std::streambuf * previousBuffer;
        public:
            StderrRecorder() : previousBuffer{ std::cerr.rdbuf(recording.rdbuf()) } {}
            ~StderrRecorder() { std::cerr.rdbuf(previousBuffer); }
            auto str() { return recording.str(); }
        };

        class StdoutRecorder {
            std::stringstream recording;
            std::streambuf * previousBuffer;
        public:
            StdoutRecorder() : previousBuffer{ std::cout.rdbuf(recording.rdbuf()) } {}
            ~StdoutRecorder() { std::cout.rdbuf(previousBuffer); }
            auto str() { return recording.str(); }
        };

    }
}