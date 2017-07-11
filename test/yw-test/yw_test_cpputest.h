#pragma once

#if defined(CPPUTEST)

#include "CppUTest/TestHarness.h"

#define YW_TEST_FIXTURE(fixture_name)    TEST_GROUP(fixture_name) {
#define YW_TEST_SETUP(fixture_name)		 void setup()
#define YW_TEST_SET                      };
#define YW_TEST(fixture_name, test_name) TEST(fixture_name, test_name)
#define YW_TEST_END 

#endif

