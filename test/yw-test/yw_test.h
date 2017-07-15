#pragma once

#include "yw_test_msvc.h"
#include "yw_test_cpputest.h"
#include "nullable.h"

namespace yw {
    namespace test {

        class Assert {
        
        public:

            static void AreEqual(const char* expected, std::string actual, bool ignoreCase = false, const wchar_t* w_message = nullptr) {
                
                #ifdef MSTEST
					MSTEST::AreEqual(expected, actual.c_str(), ignoreCase, w_message);
                #endif

                #ifdef CPPUTEST
                    STRCMP_EQUAL(expected, actual.c_str());
                #endif
            }

            static void EmptyString(std::string actual) {

                #ifdef MSTEST
					MSTEST::AreEqual("", actual.c_str());
                #endif

                #ifdef CPPUTEST
                    STRCMP_EQUAL("", actual.c_str());
                #endif
            }

            template<typename T> 
            static void IsNull(const T* actual, const wchar_t* message = nullptr) {
            
                #ifdef MSTEST
					MSTEST::IsNull(actual, message);
                #endif

                #ifdef CPPUTEST
                    POINTERS_EQUAL(nullptr, actual);
                #endif
            }

			template<typename T>
			static void IsNull(yw::sqlite::nullable<T> actual, const wchar_t* message = nullptr) {

				#ifdef MSTEST
					MSTEST::IsTrue(!actual.hasValue(), message);
				#endif

				#ifdef CPPUTEST
					CHECK(actual.isNull());
				#endif
			}


            template<typename T>
            static void AreEqual(const T& expected, const T& actual, const wchar_t* message = nullptr) {

                #ifdef MSTEST
					MSTEST::AreEqual(expected, actual, message);
                #endif

                #ifdef CPPUTEST
                    CHECK_EQUAL(expected, actual);
                #endif
            }

            static void AreEqual(const int& expected, const long& actual, const wchar_t* message = nullptr) {
                
                #ifdef MSTEST
					MSTEST::AreEqual((long)expected, actual, message);
                #endif

                #ifdef CPPUTEST
                    LONGS_EQUAL(expected, actual);
                #endif
            }

            static void AreEqual(const int& expected, const size_t& actual, const wchar_t* message = nullptr) {
                
                #ifdef MSTEST
					MSTEST::AreEqual((size_t)expected, actual, message);
                #endif

                #ifdef CPPUTEST
                    UNSIGNED_LONGS_EQUAL(expected, actual);
                #endif
            }

            static void Fail(const wchar_t* w_message = nullptr) {

                #ifdef MSTEST
					MSTEST::Fail(w_message);
                #endif      
                
                #ifdef CPPUTEST
                    FAIL((AssertMessage(w_message)).c_str());
                #endif
            }

			static void IsTrue(const bool& condition, const wchar_t* message = nullptr) {

				#ifdef MSTEST
					MSTEST::IsTrue(condition);
				#endif

				#ifdef CPPUTEST
					CHECK(condition);
				#endif
			}
		};

		class Expect : public Assert {
		};
    }
}
