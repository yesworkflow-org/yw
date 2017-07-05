#pragma once

#include "targetver.h"
#include "CppUnitTest.h"

#define YW_TEST_FIXTURE(fixture_name)    TEST_CLASS(fixture_name ## _Tests) {
#define YW_TEST_SET                      public:
#define YW_TEST(fixture_name, test_name) TEST_METHOD(Test ## fixture_name ## _ ## test_name)
#define YW_TEST_END                      };


