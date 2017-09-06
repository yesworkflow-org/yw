#include "yw_config_tests.h"

using namespace yw;
using namespace yw::config;
using namespace yw::test;

YW_TEST_FIXTURE(Configuration)

    StderrRecorder stderrRecorder;
    Configuration configuration;

YW_TEST_SET

   YW_TEST(Configuration, WhenCommandLineIsJustProgramNameProgramFieldIsSet)
    {
        Expect::AreEqual(0, configuration.size());
        configuration.insert(Setting{ "key", "value", SettingSource::UNKNOWN, "" });
        Expect::AreEqual(1, configuration.size());
        Assert::IsTrue(configuration.contains("key"));
        Assert::AreEqual("value", configuration.get("key").value);
    }


YW_TEST_END
