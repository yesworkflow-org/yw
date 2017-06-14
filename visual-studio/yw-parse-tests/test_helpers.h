#pragma once
#include "CppUnitTest.h"

namespace YW {
    namespace Assert {

        using namespace Microsoft::VisualStudio;

        static void AreEqual(
            const char* expected, std::string actual,
            bool ignoreCase = false,
            const wchar_t* message = NULL,
            const CppUnitTestFramework::__LineInfo* pLineInfo = NULL
        )
        {
            CppUnitTestFramework::Assert::AreEqual(
                expected, actual.c_str(),
                ignoreCase, message, pLineInfo
            );
        }
    }
}
