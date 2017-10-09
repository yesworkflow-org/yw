#include <map>
#include "yw_config_tests.h"

using namespace yw;
using namespace yw::config;
using namespace yw::test;
using SettingSource = Setting::SettingSource;

YW_TEST_FIXTURE(ConfigurationFile)

    StderrRecorder stderrRecorder;


YW_TEST_SET

    YW_TEST(ConfigurationFile, EmptyConfigurationTextYieldsConfigurationWithSizeIsZero)
    {
        Configuration configuration{ "" };
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(0, configuration.size());
    }

    YW_TEST(ConfigurationFile, ConfigurationSettingOnOneLineWithNoWhitespaceYieldsConfigurationWithOneSetting)
    {
        Configuration configuration{ "key=value" };
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(1, configuration.size());
        Assert::AreEqual("value", configuration.getStringValue("key"));
    }

    YW_TEST(ConfigurationFile, ConfigurationSettingOnOneLineWithWhitespaceYieldsConfigurationWithOneSetting)
    {
        Configuration configuration{ "  key = value  " };
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(1, configuration.size());
        Assert::AreEqual("value", configuration.getStringValue("key"));
    }

    YW_TEST(ConfigurationFile, ConfigurationTextWithOneHashCommentYieldsConfigurationWithSizeIsZero)
    {
        Configuration configuration{ R"(

            # a single comment

        )" };
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(0, configuration.size());
    }

    YW_TEST(ConfigurationFile, ConfigurationTextWithOneDoubleslashCommentYieldsConfigurationWithSizeIsZero)
    {
        Configuration configuration{ R"(

            // a single comment

        )" };
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(0, configuration.size());
    }


   YW_TEST(ConfigurationFile, ConfigurationTextWithOneSettingYieldsConfigurationWithOneSetting)
    {
        Configuration configuration{ R"(

            key = value

        )" };
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(1, configuration.size());
        Assert::AreEqual("value", configuration.getStringValue("key"));
   }

   YW_TEST(ConfigurationFile, ConfigurationTextWithOneSettingWithNoSpacesAroundEqualsYieldsConfigurationWithOneSetting)
   {
       Configuration configuration{ R"(

            key=value

        )" };
       Expect::EmptyString(stderrRecorder.str());

       Assert::AreEqual(1, configuration.size());
       Assert::AreEqual("value", configuration.getStringValue("key"));
   }

   YW_TEST(ConfigurationFile, ConfigurationValueContainingEqualsYieldsConfigurationWithOneSetting)
   {
       Configuration configuration{ R"(

            key = value = 3

        )" };
       Expect::EmptyString(stderrRecorder.str());

       Assert::AreEqual(1, configuration.size());
       Assert::AreEqual("value = 3", configuration.getStringValue("key"));
   }

   YW_TEST(ConfigurationFile, ConfigurationValueContainingEqualsWIthNoSpaceYieldsConfigurationWithOneSetting)
   {
       Configuration configuration{ R"(

            key=value=3

        )" };
       Expect::EmptyString(stderrRecorder.str());

       Assert::AreEqual(1, configuration.size());
       Assert::AreEqual("value=3", configuration.getStringValue("key"));
   }

   YW_TEST(ConfigurationFile, AfterInsertingTwoSettingsWithDifferentKeysConfigurationSizeIsTwo)
   {
       Configuration configuration{ R"(

            key1 = value 1 
            key2 = value 2

        )" };

       Expect::EmptyString(stderrRecorder.str());

       Assert::AreEqual(2, configuration.size());
       Assert::AreEqual("value 1", configuration.getStringValue("key1"));
       Assert::AreEqual("value 2", configuration.getStringValue("key2"));
   }

   YW_TEST(ConfigurationFile, ConfigurationTextWithOneMultiwordSettingYieldsConfigurationWithOneSetting)
   {
       Configuration configuration{ R"(

            key = multiple word value

        )" };
       Expect::EmptyString(stderrRecorder.str());

       Assert::AreEqual(1, configuration.size());
       Assert::AreEqual("multiple word value", configuration.getStringValue("key"));
   }

   YW_TEST(ConfigurationFile, ConfigurationTextWithSinglyQuotedMultiwordSettingYieldsConfigurationWithOneSetting)
   {
       Configuration configuration{ R"(

            key = 'multiple word value'

        )" };
       Expect::EmptyString(stderrRecorder.str());

       Assert::AreEqual(1, configuration.size());
       Assert::AreEqual("multiple word value", configuration.getStringValue("key"));
   }

   YW_TEST(ConfigurationFile, ConfigurationTextWithDoublyQuotedMultiwordSettingYieldsConfigurationWithOneSetting)
   {
       Configuration configuration{ R"(

            key = "multiple word value"

        )" };
       Expect::EmptyString(stderrRecorder.str());

       Assert::AreEqual(1, configuration.size());
       Assert::AreEqual("multiple word value", configuration.getStringValue("key"));
   }


   YW_TEST(ConfigurationFile, ConfigurationTextWithOneSettingLineAndOneHashCommentLineYieldsConfigurationWithOneSetting)
   {
       Configuration configuration{ R"(

            # a single comment
            key = value

        )" };
       Expect::AreEqual("", stderrRecorder.str());
       Expect::EmptyString(stderrRecorder.str());

       Assert::AreEqual(1, configuration.size());
       Assert::AreEqual("value", configuration.getStringValue("key"));
   }

   YW_TEST(ConfigurationFile, ConfigurationTextWithCommentOnSameLineAsSettingYieldsConfigurationWithOneSetting)
   {
       Configuration configuration{ R"(

            key = multiple word value   # a single comment

        )" };
       Expect::AreEqual("", stderrRecorder.str());
       Expect::EmptyString(stderrRecorder.str());

       Assert::AreEqual(1, configuration.size());
       Assert::AreEqual("multiple word value", configuration.getStringValue("key"));
   }

   YW_TEST(ConfigurationFile, ConfigurationTextWithCommentOnSameLineAsQuotedSettingWithTerminalSpacesYieldsConfigurationValueWithTerminalSpaces)
   {
       Configuration configuration{ R"(

            key = '  multiple word value  ' # a single comment

        )" };
       Expect::AreEqual("", stderrRecorder.str());
       Expect::EmptyString(stderrRecorder.str());

       Assert::AreEqual(1, configuration.size());
       Assert::AreEqual("  multiple word value  ", configuration.getStringValue("key"));
    }

YW_TEST_END
