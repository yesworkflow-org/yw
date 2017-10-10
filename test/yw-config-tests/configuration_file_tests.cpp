#include <map>
#include "yw_config_tests.h"

using namespace yw;
using namespace yw::config;
using namespace yw::test;
using SettingSource = Setting::SettingSource;

YW_TEST_FIXTURE(ConfigurationFile)

    Configuration configuration;
    StderrRecorder stderrRecorder;

YW_TEST_SET

    YW_TEST(ConfigurationFile, EmptyConfigurationTextYieldsConfigurationWithSizeIsZero)
    {
        auto configFilePath = writeTempFile( "yw.properties", "" );

        configuration.insertSettingsFromFile(configFilePath);
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(0, configuration.size());
    }

    YW_TEST(ConfigurationFile, ConfigurationSettingOnOneLineWithNoWhitespaceYieldsConfigurationWithOneSetting)
    {
        auto configFilePath = writeTempFile( "yw.properties", "key=value" );
        configuration.insertSettingsFromFile(configFilePath);
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(1, configuration.size());
        Assert::AreEqual("value", configuration.getStringValue("key"));
    }

   YW_TEST(ConfigurationFile, AfterInsertingTwoSettingsWithDifferentKeysConfigurationSizeIsTwo)
   {
       auto configFilePath = writeTempFile("yw.properties", R"(

            key1 = value 1 
            key2 = value 2

        )" );
       configuration.insertSettingsFromFile(configFilePath);
       Expect::EmptyString(stderrRecorder.str());

       Assert::AreEqual(2, configuration.size());
       Assert::AreEqual("value 1", configuration.getStringValue("key1"));
       Assert::AreEqual("value 2", configuration.getStringValue("key2"));
   }

   YW_TEST(ConfigurationFile, ConfigurationTextWithOneSettingLineAndOneHashCommentLineYieldsConfigurationWithOneSetting)
   {
       auto configFilePath = writeTempFile("yw.properties", R"(
            # a single comment
            key = value

        )" );
       configuration.insertSettingsFromFile(configFilePath);
       Expect::EmptyString(stderrRecorder.str());

       Assert::AreEqual(1, configuration.size());
       Assert::AreEqual("value", configuration.getStringValue("key"));
   }

   YW_TEST(ConfigurationFile, ConfigurationTextWithCommentOnSameLineAsSettingYieldsConfigurationWithOneSetting)
   {
       auto configFilePath = writeTempFile("yw.properties", R"(

            key = multiple word value   # a single comment

        )" );
       configuration.insertSettingsFromFile(configFilePath);
       Expect::EmptyString(stderrRecorder.str());

       Assert::AreEqual(1, configuration.size());
       Assert::AreEqual("multiple word value", configuration.getStringValue("key"));
   }

YW_TEST_END
