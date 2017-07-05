#pragma once

#ifdef _MSC_VER 
#include "yw_test_msvc.h"
#endif

#ifdef CPPUTEST
#include "yw_test_cpputest.h"
#endif

#include <string>

namespace yw {
    namespace test {

#ifdef _MSC_VER
        using namespace Microsoft::VisualStudio;
#endif

        class Assert {
        
        public:

            static void AreEqual(const char* expected, std::string actual, bool ignoreCase = false, const wchar_t* message = NULL) {
                #ifdef _MSC_VER
                CppUnitTestFramework::Assert::AreEqual(expected, actual.c_str(), ignoreCase, message);
                #endif
            }

            template<typename T> 
            static void IsNull(const T* actual, const wchar_t* message = NULL) {
                #ifdef _MSC_VER
                CppUnitTestFramework::Assert::IsNull(actual, message);
                #endif
            }

            template<typename T>
            static void AreEqual(const T& expected, const T& actual, const wchar_t* message = NULL) {
                #ifdef _MSC_VER
                CppUnitTestFramework::Assert::AreEqual(expected, actual, message);
                #endif
            }

            static void AreEqual(const int& expected, const long& actual, const wchar_t* message = NULL) {
                #ifdef _MSC_VER
                CppUnitTestFramework::Assert::AreEqual((long)expected, actual, message);
                #endif
            }

            static void AreEqual(const int& expected, const size_t& actual, const wchar_t* message = NULL) {
                #ifdef _MSC_VER
                CppUnitTestFramework::Assert::AreEqual((size_t)expected, actual, message);
                #endif
            }

            static void Fail(const wchar_t* message = NULL) {
                #ifdef _MSC_VER
                CppUnitTestFramework::Assert::Fail(message);
                #endif
            }
        };
    }
}
