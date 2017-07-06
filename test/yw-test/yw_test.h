#pragma once

#include "yw_test_msvc.h"
#include "yw_test_cpputest.h"

#include <string>

namespace yw {
    namespace test {

        inline const char * get_c_message(const wchar_t * w_message) {
            if (w_message == nullptr) w_message = L"";
            size_t newsize = (wcslen(w_message) + 1) * 2;
            char *c_message = new char[newsize];
            wcstombs_s(nullptr, c_message, newsize, w_message, _TRUNCATE);
            return c_message;
        }

        class Assert {
        
        public:

            static void AreEqual(const char* expected, std::string actual, bool ignoreCase = false, const wchar_t* message = NULL) {
                #if defined(MSTEST)
                    Microsoft::VisualStudio::CppUnitTestFramework::
                    Assert::AreEqual(expected, actual.c_str(), ignoreCase, message);
                #endif
            }

            template<typename T> 
            static void IsNull(const T* actual, const wchar_t* message = NULL) {
                #if defined(MSTEST)
                    Microsoft::VisualStudio::CppUnitTestFramework::
                    Assert::IsNull(actual, message);
                #endif
            }

            template<typename T>
            static void AreEqual(const T& expected, const T& actual, const wchar_t* message = NULL) {
                #if defined(MSTEST)
                    Microsoft::VisualStudio::CppUnitTestFramework::
                    Assert::AreEqual(expected, actual, message);
                #endif
            }

            static void AreEqual(const int& expected, const long& actual, const wchar_t* message = NULL) {
                #if defined(MSTEST)
                    Microsoft::VisualStudio::CppUnitTestFramework::
                    Assert::AreEqual((long)expected, actual, message);
                #endif
            }

            static void AreEqual(const int& expected, const size_t& actual, const wchar_t* message = NULL) {
                #if defined(MSTEST)
                    Microsoft::VisualStudio::CppUnitTestFramework::
                    Assert::AreEqual((size_t)expected, actual, message);
                #endif
            }

            static void Fail(const wchar_t* w_message = NULL) {
                #if defined(MSTEST)
                    Microsoft::VisualStudio::CppUnitTestFramework::
                    Assert::Fail(w_message);
                #elif defined(CPPUTEST)
                    auto c_message = get_c_message(w_message);
                    FAIL(c_message);
                    delete[] c_message;
                #endif
            }
        };
    }
}
