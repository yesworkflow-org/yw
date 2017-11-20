#include <map>
#include "yw_config_tests.h"

using namespace yw;
using namespace yw::config;
using namespace yw::test;
using SettingSource = Setting::SettingSource;

YW_TEST_FIXTURE(Configuration)

    Configuration configuration;

YW_TEST_SET

    YW_TEST(Configuration, BeforeInsertingAnySettingConfigurationSizeIsZero)
    {
        Assert::AreEqual(0, configuration.size());
    }

    YW_TEST(Configuration, AfterInsertingOneSettingConfigurationSizeIsOne)
    {
        configuration.insert(Setting{ "key", "value" });
        Assert::AreEqual(1, configuration.size());
    }

    YW_TEST(Configuration, AfterInsertingTwoSettingsWithDifferentKeysConfigurationSizeIsTwo)
    {
        configuration.insert(Setting{ "key1", "value1" });
        configuration.insert(Setting{ "key2", "value2" });
        Assert::AreEqual(2, configuration.size());
    }

    YW_TEST(Configuration, AfterInsertingTwoSettingsWithSameKeyConfigurationSizeIsOne)
    {
        configuration.insert(Setting{ "key1", "value1" });
        configuration.insert(Setting{ "key1", "value2" });
        Assert::AreEqual(1, configuration.size());
    }

    YW_TEST(Configuration, AfterInsertingTwoSettingsWithSameKeyButDifferentCaseConfigurationSizeIsOne)
    {
        configuration.insert(Setting{ "key1", "value1" });
        configuration.insert(Setting{ "KEY1", "value2" });
        Assert::AreEqual(1, configuration.size());
    }

    YW_TEST(Configuration, AfterInsertingOneSettingGetReturnsSettingWithInsertedKeyAndValue)
    {
        configuration.insert(Setting{ "key", "value" });
        Assert::AreEqual("value", configuration.getValueText("key"));
    }

    YW_TEST(Configuration, AfterInsertingOneSettingGetUsingDifferentlyCasedKeyReturnsSettingWithInsertedKeyAndValue)
    {
        configuration.insert(Setting{ "key", "value" });
        Assert::AreEqual("value", configuration.getValueText("KEY"));
    }

    YW_TEST(Configuration, AfterInsertingTwoSettingsWithDifferentKeysGetOnSecondKeyReturnsSettingWithSecondInsertedKeyAndValue)
    {
        configuration.insert(Setting{ "key1", "value1" });
        configuration.insert(Setting{ "key2", "value2" });
        Expect::AreEqual(2, configuration.size());
        Assert::AreEqual("value2", configuration.getValueText("key2"));
    }

    YW_TEST(Configuration, AfterInsertingTwoSettingsWithSameKeyAndUnspecifiedSourceGetOReturnsSettingWithSecondInsertedValue)
    {
        configuration.insert(Setting{ "key1", "value1" });
        configuration.insert(Setting{ "key1", "value2" });
        Expect::AreEqual(1, configuration.size());
        Assert::AreEqual("value2", configuration.getValueText("key1"));
    }

    YW_TEST(Configuration, AfterInsertingOneSettingWithSpecifiedSourceGetReturnsSettingWithThatSource)
    {
        configuration.insert(Setting{ "key", "value", SettingSource::YW_DEFAULTS });
        Expect::AreEqual(1, configuration.size());
        Assert::IsTrue(SettingSource::YW_DEFAULTS == configuration.getSetting("key").source);
    }

    YW_TEST(Configuration, AfterInsertingTowSettingWithDifferentKeysAndSpecifiedSourcesGetReturnsSettingWithCorrectSources)
    {
        configuration.insert(Setting{ "key1", "value1", SettingSource::YW_DEFAULTS });
        configuration.insert(Setting{ "key2", "value2", SettingSource::COMMAND_LINE });
        Expect::AreEqual(2, configuration.size());
        Assert::IsTrue(SettingSource::YW_DEFAULTS == configuration.getSetting("key1").source);
        Assert::IsTrue(SettingSource::COMMAND_LINE == configuration.getSetting("key2").source);
    }

    YW_TEST(Configuration, AfterInsertingTwoSettingWithSameKeyAndSameSourcesGetReturnsSettingWithSecondInsertedValue)
    {
        configuration.insert(Setting{ "key1", "value1", SettingSource::YW_DEFAULTS });
        configuration.insert(Setting{ "key1", "value2", SettingSource::YW_DEFAULTS });
        Expect::AreEqual(1, configuration.size());
        Expect::IsTrue(SettingSource::YW_DEFAULTS == configuration.getSetting("key1").source);
        Assert::AreEqual("value2", configuration.getValueText("key1"));
    }

    YW_TEST(Configuration, AfterInsertingTwoSettingWithSameKeysButSecondWithSourceOfHigherPriorityGetReturnsSettingWithSecondInsertedValueAndSecondSource)
    {
        configuration.insert(Setting{ "key1", "value1", SettingSource::YW_DEFAULTS });
        configuration.insert(Setting{ "key1", "value2", SettingSource::USER_DEFAULTS });
        Expect::AreEqual(1, configuration.size());
        Expect::IsTrue(SettingSource::USER_DEFAULTS == configuration.getSetting("key1").source);
        Assert::AreEqual("value2", configuration.getValueText("key1"));
    }

    YW_TEST(Configuration, AfterInsertingTwoSettingWithSameKeysButSecondWithSourceOfLowerPriorityGetReturnsSettingWithFirstInsertedValueAndFirstSource)
    {
        configuration.insert(Setting{ "key1", "value1", SettingSource::USER_DEFAULTS });
        configuration.insert(Setting{ "key1", "value2", SettingSource::YW_DEFAULTS });
        Expect::AreEqual(1, configuration.size());
        Expect::IsTrue(SettingSource::USER_DEFAULTS == configuration.getSetting("key1").source);
        Assert::AreEqual("value1", configuration.getValueText("key1"));
    }
    
    YW_TEST(Configuration, InsertingOneConfigurationIntoAnotherWithDisjointKeysYieldsUnionOfSettings) {

        configuration.insert(Setting{ "key1", "value1" });
        configuration.insert(Setting{ "key2", "value2" });
        Configuration otherConfiguration;
        otherConfiguration.insert(Setting{ "key3", "value3" });
        otherConfiguration.insert(Setting{ "key4", "value4" });
        configuration.insertAll(otherConfiguration);

        Assert::AreEqual(4, configuration.size());
        Assert::AreEqual("value1", configuration.getValueText("key1"));
        Assert::AreEqual("value2", configuration.getValueText("key2"));
        Assert::AreEqual("value3", configuration.getValueText("key3"));
        Assert::AreEqual("value4", configuration.getValueText("key4"));
    }

    YW_TEST(Configuration, InsertingOneConfigurationIntoAnotherWithOneHigherPrioritySettingWithCommonKeyYieldsMergedSettingsWithOverriddenSetting) {

        configuration.insert(Setting{ "key1", "value1", SettingSource::YW_DEFAULTS });
        configuration.insert(Setting{ "key2", "value2", SettingSource::YW_DEFAULTS });
        Configuration otherConfiguration;
        otherConfiguration.insert(Setting{ "key2", "other2", SettingSource::COMMAND_LINE });
        otherConfiguration.insert(Setting{ "key3", "value3", SettingSource::COMMAND_LINE });
        configuration.insertAll(otherConfiguration);

        Assert::AreEqual(3, configuration.size());
        Assert::AreEqual("value1", configuration.getValueText("key1"));
        Assert::AreEqual("other2", configuration.getValueText("key2"));
        Assert::AreEqual("value3", configuration.getValueText("key3"));
    }

    YW_TEST(Configuration, InsertingOneConfigurationIntoAnotherWithOneHigherPrioritySettingWithCommonButDifferentlyCasedKeyYieldsMergedSettingsWithOverriddenSetting) {

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

YW_TEST_END
