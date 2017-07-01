#pragma once

#include "yw_test.h"

#include "CppUnitTest.h"
#include <string>

namespace yw {
    namespace test {

        using namespace Microsoft::VisualStudio;

        class Assert {
        
        public:

            static void AreEqual(const char* expected, std::string actual, bool ignoreCase = false, const wchar_t* message = NULL) {
                CppUnitTestFramework::Assert::AreEqual(expected, actual.c_str(), ignoreCase, message);
            }

            template<typename T> 
            static void IsNull(const T* actual, const wchar_t* message = NULL) {
                CppUnitTestFramework::Assert::IsNull(actual, message);
            }

            template<typename T>
            static void AreEqual(const T& expected, const T& actual, const wchar_t* message = NULL) {
                CppUnitTestFramework::Assert::AreEqual(expected, actual, message);
            }

            static void AreEqual(const int& expected, const long& actual, const wchar_t* message = NULL) {
                CppUnitTestFramework::Assert::AreEqual((long)expected, actual, message);
            }

            static void AreEqual(const int& expected, const size_t& actual, const wchar_t* message = NULL) {
                CppUnitTestFramework::Assert::AreEqual((size_t)expected, actual, message);
            }

            static void Fail(const wchar_t* message = NULL) {
                CppUnitTestFramework::Assert::Fail(message);
            }
        };
    }
}
