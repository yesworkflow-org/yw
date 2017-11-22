#include <map>
#include "yw_config_tests.h"

using namespace yw;
using namespace yw::config;
using namespace yw::test;
using SettingSource = Setting::SettingSource;

YW_TEST_FIXTURE(CaseInsensitiveSettings)

    Configuration configuration;

YW_TEST_SET

    YW_TEST(CaseInsensitiveSettings, SettingHelpForUpperCaseSettingNamesShowsAllLowercaseSettingName)
    {
        auto setting = Setting{ "SETTING1" };
        Assert::AreEqual( "setting1", setting.str());
    }

    YW_TEST(CaseInsensitiveSettings, SettingHelpForMixedCaseSettingNamesShowsAllLowercaseSettingName)
    {
        auto setting = Setting{ "Setting1" };
        Assert::AreEqual("setting1", setting.str());
    }

    YW_TEST(CaseInsensitiveSettings, AfterInsertingOneSettingGetUsingDifferentlyCasedKeyReturnsSettingWithInsertedKeyAndValue)
    {
        configuration.insert(Setting{ "key", "value" });
        Assert::AreEqual("value", configuration.getValueText("KEY"));
    }

    YW_TEST(CaseInsensitiveSettings, SettingHelpForMixedCaseAllosedValuesShowsAllUppercaseValues)
    {
        auto setting = Setting{ "setting1" , "two", "First setting",{ "ONE", "Two", "three" } };
        Assert::AreEqual("setting1    First setting (ONE, TWO*, or THREE)", setting.str(12));
    }

    YW_TEST(CaseInsensitiveSettings, SettingConstructorThrowsExceptionIfDefaultValueNotInAllowedValues)
    {
        try {
            auto setting = Setting{ "setting1" , "zero", "First setting",{ "ONE", "Two", "three" } };
        }
        catch (std::domain_error e) {
            Assert::AreEqual(
                "Default value of ZERO is not one of the allowed values (ONE, TWO, or THREE) for setting 'setting1'.", 
                e.what());
        }
    }

    YW_TEST(CaseInsensitiveSettings, AfterInsertingTwoSettingsWithSameKeyButDifferentCaseConfigurationSizeIsOne)
    {
        configuration.insert(Setting{ "key1", "value1" });
        configuration.insert(Setting{ "KEY1", "value2" });
        Assert::AreEqual(1, configuration.size());
    }

    YW_TEST(CaseInsensitiveSettings, ValueTextForSettingCanBeRetrievedWithDifferentCaseThanOriginalSettingKey)
    {
        configuration.insert(Setting{ "setting1", "value1" });
        Assert::AreEqual("value1", configuration.getValueText("setting1"));
        Assert::AreEqual("value1", configuration.getValueText("SETTING1"));
        Assert::AreEqual("value1", configuration.getValueText("Setting1"));
    }

    YW_TEST(CaseInsensitiveSettings, ConfigurationHelpForMixedCaseSettingNamesShowsAllLowercaseSettingNames)
    {
        configuration.insert(Setting{ "setting1" });
        configuration.insert(Setting{ "SETTING2" });
        configuration.insert(Setting{ "Setting3" });

        Assert::AreEqual(trimmargins(R"(
                setting1
                setting2
                setting3
            )"), configuration.help()
        );
    }

    YW_TEST(CaseInsensitiveSettings, InsertingOneConfigurationIntoAnotherWithOneHigherPrioritySettingWithCommonButDifferentlyCasedKeyYieldsMergedSettingsWithOverriddenSetting) {

        configuration.insert(Setting{ "key1", "value1", SettingSource::YW_DEFAULTS });
        configuration.insert(Setting{ "key2", "value2", SettingSource::YW_DEFAULTS });
        Configuration otherConfiguration;
        otherConfiguration.insert(Setting{ "KEY2", "other2", SettingSource::COMMAND_LINE });
        otherConfiguration.insert(Setting{ "key3", "value3", SettingSource::COMMAND_LINE });
        configuration.insertAll(otherConfiguration);

        Assert::AreEqual(3, configuration.size());
        Assert::AreEqual("value1", configuration.getValueText("key1"));
        Assert::AreEqual("other2", configuration.getValueText("key2"));
        Assert::AreEqual("value3", configuration.getValueText("key3"));
    }

    YW_TEST(CaseInsensitiveSettings, ConfigurationHelpForSettingsWithMixCaseAllowedValesShowsAllUppercaseValues)
    {
        configuration.insert(Setting{ "setting1" , "ONE", "First setting", {"ONE", "Two", "three"} });
        configuration.insert(Setting{ "setting2" , null_string, "Second setting" });
        configuration.insert(Setting{ "setting3" , null_string, "First setting" });

        Assert::AreEqual(trimmargins(R"(
                setting1                   First setting (ONE*, TWO, or THREE)
                setting2                   Second setting
                setting3                   First setting
            )"), configuration.help()
        );
    }

    YW_TEST(CaseInsensitiveSettings, ConfigurationHelpForSettingsShowsDefaultWhenDefaultCaseDifferentFromAllowedValeuCase)
    {
        configuration.insert(Setting{ "setting1" , "two", "First setting",{ "ONE", "Two", "three" } });
        configuration.insert(Setting{ "setting2" , null_string, "Second setting" });
        configuration.insert(Setting{ "setting3" , null_string, "First setting" });

        Assert::AreEqual(trimmargins(R"(
                setting1                   First setting (ONE, TWO*, or THREE)
                setting2                   Second setting
                setting3                   First setting
            )"), configuration.help()
        );
    }

    YW_TEST(CaseInsensitiveSettings, C)
    {
        configuration.insert(Setting{ "setting1" , "two", "First setting",{ "ONE", "Two", "three" } });
        try {
            configuration.insert(Setting{ "setting1", "four", Setting::SettingSource::COMMAND_LINE });
        }
        catch (std::domain_error e) {
            Assert::AreEqual(
                "Setting value FOUR is not one of the allowed values (ONE, TWO*, or THREE) for setting 'setting1'.",
                e.what());
        }

    }
YW_TEST_END
