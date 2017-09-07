#include "yw_config_tests.h"

using namespace yw;
using namespace yw::config;
using namespace yw::test;

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

    YW_TEST(Configuration, AfterInsertingOneSettingGetReturnsSettingWIthInsertedKeyAndValue)
    {
        configuration.insert(Setting{ "key", "value" });
        Assert::AreEqual("key", configuration.get("key").key);
        Assert::AreEqual("value", configuration.get("key").value.getValue());
    }

    YW_TEST(Configuration, AfterInsertingTwoSettingsWithDifferentKeysGetOnSecondKeyReturnsSettingWithSecondInsertedKeyAndValue)
    {
        configuration.insert(Setting{ "key1", "value1" });
        configuration.insert(Setting{ "key2", "value2" });
        Expect::AreEqual(2, configuration.size());
        Assert::AreEqual("key2", configuration.get("key2").key);
        Assert::AreEqual("value2", configuration.get("key2").value.getValue());
    }

    YW_TEST(Configuration, AfterInsertingTwoSettingsWithSameKeyAndUnspecifiedSourceGetOReturnsSettingWithSecondInsertedValue)
    {
        configuration.insert(Setting{ "key1", "value1" });
        configuration.insert(Setting{ "key1", "value2" });
        Expect::AreEqual(1, configuration.size());
        Expect::AreEqual("key1", configuration.get("key1").key);
        Assert::AreEqual("value2", configuration.get("key1").value.getValue());
    }

    YW_TEST(Configuration, AfterInsertingOneSettingWithSpecifiedSourceGetReturnsSettingWithThatSource)
    {
        configuration.insert(Setting{ "key", "value", Source::YW_DEFAULTS });
        Expect::AreEqual(1, configuration.size());
        Assert::IsTrue(Source::YW_DEFAULTS == configuration.get("key").source);
    }

    YW_TEST(Configuration, AfterInsertingTowSettingWithDifferentKeysAndSpecifiedSourcesGetReturnsSettingWithCorrectSources)
    {
        configuration.insert(Setting{ "key1", "value1", Source::YW_DEFAULTS });
        configuration.insert(Setting{ "key2", "value2", Source::COMMAND_LINE });
        Expect::AreEqual(2, configuration.size());
        Assert::IsTrue(Source::YW_DEFAULTS == configuration.get("key1").source);
        Assert::IsTrue(Source::COMMAND_LINE == configuration.get("key2").source);
    }

    YW_TEST(Configuration, AfterInsertingTwoSettingWithSameKeyAndSameSourcesGetReturnsSettingWithSecondInsertedValue)
    {
        configuration.insert(Setting{ "key1", "value1", Source::YW_DEFAULTS });
        configuration.insert(Setting{ "key1", "value2", Source::YW_DEFAULTS });
        Expect::AreEqual(1, configuration.size());
        Expect::IsTrue(Source::YW_DEFAULTS == configuration.get("key1").source);
        Expect::AreEqual("key1", configuration.get("key1").key);
        Assert::AreEqual("value2", configuration.get("key1").value.getValue());
    }

    YW_TEST(Configuration, AfterInsertingTwoSettingWithSameKeysButSecondWithSourceOfHigherPriorityGetReturnsSettingWithSecondInsertedValueAndSecondSource)
    {
        configuration.insert(Setting{ "key1", "value1", Source::YW_DEFAULTS });
        configuration.insert(Setting{ "key1", "value2", Source::USER_DEFAULTS });
        Expect::AreEqual(1, configuration.size());
        Expect::IsTrue(Source::USER_DEFAULTS == configuration.get("key1").source);
        Expect::AreEqual("key1", configuration.get("key1").key);
        Assert::AreEqual("value2", configuration.get("key1").value.getValue());
    }

    YW_TEST(Configuration, AfterInsertingTwoSettingWithSameKeysButSecondWithSourceOfLowerPriorityGetReturnsSettingWithFirstInsertedValueAndFirstSource)
    {
        configuration.insert(Setting{ "key1", "value1", Source::USER_DEFAULTS });
        configuration.insert(Setting{ "key1", "value2", Source::YW_DEFAULTS });
        Expect::AreEqual(1, configuration.size());
        Expect::IsTrue(Source::USER_DEFAULTS == configuration.get("key1").source);
        Expect::AreEqual("key1", configuration.get("key1").key);
        Assert::AreEqual("value1", configuration.get("key1").value.getValue());
    }
    
    YW_TEST(Configuration, InsertingOneConfigurationIntoAnotherWithDisjointKeysYieldsUnionOfSettings) {

        configuration.insert(Setting{ "key1", "value1" });
        configuration.insert(Setting{ "key2", "value2" });
        Configuration otherConfiguration;
        otherConfiguration.insert(Setting{ "key3", "value3" });
        otherConfiguration.insert(Setting{ "key4", "value4" });
        configuration.insertAll(otherConfiguration);

        Assert::AreEqual(4, configuration.size());
        Assert::AreEqual("value1", configuration.get("key1").value.getValue());
        Assert::AreEqual("value2", configuration.get("key2").value.getValue());
        Assert::AreEqual("value3", configuration.get("key3").value.getValue());
        Assert::AreEqual("value4", configuration.get("key4").value.getValue());
    }

    YW_TEST(Configuration, InsertingOneConfigurationIntoAnotherWithOneHigherPrioritySettingWithCommonKeyYieldsMergedSettingsWithOverriddenSetting) {

        configuration.insert(Setting{ "key1", "value1", Source::YW_DEFAULTS });
        configuration.insert(Setting{ "key2", "value2", Source::YW_DEFAULTS });
        Configuration otherConfiguration;
        otherConfiguration.insert(Setting{ "key2", "other2", Source::COMMAND_LINE });
        otherConfiguration.insert(Setting{ "key3", "value3", Source::COMMAND_LINE });
        configuration.insertAll(otherConfiguration);

        Assert::AreEqual(3, configuration.size());
        Assert::AreEqual("value1", configuration.get("key1").value.getValue());
        Assert::AreEqual("other2", configuration.get("key2").value.getValue());
        Assert::AreEqual("value3", configuration.get("key3").value.getValue());
    }

YW_TEST_END
