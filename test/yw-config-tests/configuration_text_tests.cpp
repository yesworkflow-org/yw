#include <map>
#include "yw_config_tests.h"

using namespace yw;
using namespace yw::config;
using namespace yw::test;
using SettingSource = Setting::SettingSource;

YW_TEST_FIXTURE(ConfigurationText)

    Configuration configuration;
    StderrRecorder stderrRecorder;

YW_TEST_SET

    YW_TEST(ConfigurationText, EmptyConfigurationTextYieldsConfigurationWithSizeIsZero)
    {
        configuration.insertSettingsFromText("");
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(0, configuration.size());
    }

    YW_TEST(ConfigurationText, ConfigurationSettingOnOneLineWithNoWhitespaceYieldsConfigurationWithOneSetting)
    {
        configuration.insertSettingsFromText( "key=value" );
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(1, configuration.size());
        Assert::AreEqual("value", configuration.getValueText("key"));
    }

    YW_TEST(ConfigurationText, ConfigurationSettingOnOneLineWithWhitespaceYieldsConfigurationWithOneSetting)
    {
        configuration.insertSettingsFromText("  key = value  " );
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(1, configuration.size());
        Assert::AreEqual("value", configuration.getValueText("key"));
    }

    YW_TEST(ConfigurationText, ConfigurationTextWithOneHashCommentYieldsConfigurationWithSizeIsZero)
    {
        configuration.insertSettingsFromText(R"(

            # a single comment

        )" );
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(0, configuration.size());
    }

    YW_TEST(ConfigurationText, ConfigurationTextWithOneDoubleslashCommentYieldsConfigurationWithSizeIsZero)
    {
        configuration.insertSettingsFromText(R"(

            // a single comment

        )" );
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(0, configuration.size());
    }


   YW_TEST(ConfigurationText, ConfigurationTextWithOneSettingYieldsConfigurationWithOneSetting)
    {
       configuration.insertSettingsFromText( R"(

            key = value

        )" );
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(1, configuration.size());
        Assert::AreEqual("value", configuration.getValueText("key"));
   }

   YW_TEST(ConfigurationText, ConfigurationTextWithOneSettingWithNoSpacesAroundEqualsYieldsConfigurationWithOneSetting)
   {
       configuration.insertSettingsFromText(R"(

            key=value

        )" );
       Expect::EmptyString(stderrRecorder.str());

       Assert::AreEqual(1, configuration.size());
       Assert::AreEqual("value", configuration.getValueText("key"));
   }

   YW_TEST(ConfigurationText, AfterInsertingTwoSettingsWithDifferentKeysConfigurationSizeIsTwo)
   {
       configuration.insertSettingsFromText(R"(

            key1 = value 1 
            key2 = value 2

        )" );

       Expect::EmptyString(stderrRecorder.str());

       Assert::AreEqual(2, configuration.size());
       Assert::AreEqual("value 1", configuration.getValueText("key1"));
       Assert::AreEqual("value 2", configuration.getValueText("key2"));
   }

   YW_TEST(ConfigurationText, ConfigurationTextWithOneMultiwordSettingYieldsConfigurationWithOneSetting)
   {
       configuration.insertSettingsFromText(R"(

            key = multiple word value

        )" );
       Expect::EmptyString(stderrRecorder.str());

       Assert::AreEqual(1, configuration.size());
       Assert::AreEqual("multiple word value", configuration.getValueText("key"));
   }

   YW_TEST(ConfigurationText, ConfigurationTextWithSinglyQuotedMultiwordSettingYieldsConfigurationWithOneSetting)
   {
       configuration.insertSettingsFromText(R"(

            key = 'multiple word value'

        )" );
       Expect::EmptyString(stderrRecorder.str());

       Assert::AreEqual(1, configuration.size());
       Assert::AreEqual("multiple word value", configuration.getValueText("key"));
   }

   YW_TEST(ConfigurationText, ConfigurationTextWithDoublyQuotedMultiwordSettingYieldsConfigurationWithOneSetting)
   {
       configuration.insertSettingsFromText( R"(

            key = "multiple word value"

        )" );
       Expect::EmptyString(stderrRecorder.str());

       Assert::AreEqual(1, configuration.size());
       Assert::AreEqual("multiple word value", configuration.getValueText("key"));
   }


   YW_TEST(ConfigurationText, ConfigurationTextWithOneSettingLineAndOneHashCommentLineYieldsConfigurationWithOneSetting)
   {
       configuration.insertSettingsFromText(R"(

            # a single comment
            key = value

        )" );
       Expect::AreEqual("", stderrRecorder.str());
       Expect::EmptyString(stderrRecorder.str());

       Assert::AreEqual(1, configuration.size());
       Assert::AreEqual("value", configuration.getValueText("key"));
   }

   YW_TEST(ConfigurationText, ConfigurationTextWithCommentOnSameLineAsSettingYieldsConfigurationWithOneSetting)
   {
       configuration.insertSettingsFromText(R"(

            key = multiple word value   # a single comment

        )" );
       Expect::EmptyString(stderrRecorder.str());

       Assert::AreEqual(1, configuration.size());
       Assert::AreEqual("multiple word value", configuration.getValueText("key"));
   }

   YW_TEST(ConfigurationText, ConfigurationTextWithCommentOnSameLineAsQuotedSettingWithTerminalSpacesYieldsConfigurationValueWithTerminalSpaces)
   {
       configuration.insertSettingsFromText(R"(

            key = '  multiple word value  ' # a single comment

        )" );
       Expect::AreEqual("", stderrRecorder.str());
       Expect::EmptyString(stderrRecorder.str());

       Assert::AreEqual(1, configuration.size());
       Assert::AreEqual("  multiple word value  ", configuration.getValueText("key"));
    }

YW_TEST_END
