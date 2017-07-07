#pragma once

#include "yw_test_msvc.h"
#include "yw_test_cpputest.h"

#include <string>
#include <iostream>


namespace yw {
    namespace test {

        inline const char * get_c_message(const wchar_t * w_message) {
            if (w_message == nullptr) w_message = L"";
            size_t newsize = (wcslen(w_message) + 1) * 2;
            char *c_message = new char[newsize];
            wcstombs_s(nullptr, c_message, newsize, w_message, _TRUNCATE);
            return c_message;
        }

        class StderrRecorder {
            std::stringstream recording;
            std::streambuf * previousBuffer;
        public:
            StderrRecorder()  { previousBuffer = std::cerr.rdbuf(recording.rdbuf()); }
            ~StderrRecorder() { std::cerr.rdbuf(previousBuffer); }
            std::string str() { return recording.str(); }
        };


        class Assert {
        
        public:

            static void AreEqual(const char* expected, std::string actual, bool ignoreCase = false, const wchar_t* w_message = NULL) {
                
                #ifdef MSTEST
                    Microsoft::VisualStudio::CppUnitTestFramework::
                    Assert::AreEqual(expected, actual.c_str(), ignoreCase, w_message);
                #endif

                #ifdef CPPUTEST
                    STRCMP_EQUAL(expected, actual.c_str());
                #endif
            }

            static void EmptyString(std::string actual) {

                #ifdef MSTEST
                Microsoft::VisualStudio::CppUnitTestFramework::
                    Assert::AreEqual("", actual.c_str());
                #endif

                #ifdef CPPUTEST
                    STRCMP_EQUAL("", actual.c_str());
                #endif
            }

            template<typename T> 
            static void IsNull(const T* actual, const wchar_t* message = NULL) {
            
                #ifdef MSTEST
                    Microsoft::VisualStudio::CppUnitTestFramework::
                    Assert::IsNull(actual, message);
                #endif

                #ifdef CPPUTEST
                    POINTERS_EQUAL(nullptr, actual);
                #endif
            }

            template<typename T>
            static void AreEqual(const T& expected, const T& actual, const wchar_t* message = NULL) {

                #ifdef MSTEST
                    Microsoft::VisualStudio::CppUnitTestFramework::
                    Assert::AreEqual(expected, actual, message);
                #endif

                #ifdef CPPUTEST
                    CHECK_EQUAL(expected, actual);
                #endif
            }

            static void AreEqual(const int& expected, const long& actual, const wchar_t* message = NULL) {
                
                #ifdef MSTEST
                    Microsoft::VisualStudio::CppUnitTestFramework::
                    Assert::AreEqual((long)expected, actual, message);
                #endif

                #ifdef CPPUTEST
                    LONGS_EQUAL(expected, actual);
                #endif
            }

            static void AreEqual(const int& expected, const size_t& actual, const wchar_t* message = NULL) {
                
                #ifdef MSTEST
                    Microsoft::VisualStudio::CppUnitTestFramework::
                    Assert::AreEqual((size_t)expected, actual, message);
                #endif

                #ifdef CPPUTEST
                    UNSIGNED_LONGS_EQUAL(expected, actual);
                #endif
            }

            static void Fail(const wchar_t* w_message = NULL) {

                #ifdef MSTEST
                    Microsoft::VisualStudio::CppUnitTestFramework::
                    Assert::Fail(w_message);
                #endif      
                
                #ifdef CPPUTEST
                        auto c_message = get_c_message(w_message);
                    FAIL(c_message);
                    delete[] c_message;
                #endif
            }
        };
    }
}
