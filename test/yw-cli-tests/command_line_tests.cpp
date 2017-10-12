#include "yw_cli_tests.h"

using namespace yw;
using namespace yw::cli;
using namespace yw::test;

YW_TEST_FIXTURE(CommandLine)

    StderrRecorder stderrRecorder;

YW_TEST_SET

   YW_TEST(CommandLine, WhenCommandLineIsJustProgramNameProgramFieldIsSet)
    {
        CommandLine commandLine{ "yw" };
        Expect::IsNull(commandLine.getCommand());
        Expect::AreEqual(0, commandLine.getFlags().size());
        Expect::AreEqual(0, commandLine.getArguments().size());
        Expect::AreEqual(0, commandLine.getSettings().size());

        Assert::AreEqual("yw", commandLine.getProgram());
    }

   YW_TEST(CommandLine, WhenCommandLineIsProgramNameAndShortHelpFlagFlagFieldIsSet)
    {
       CommandLine commandLine{ "yw -h" };
       Expect::AreEqual("yw", commandLine.getProgram());
       Expect::IsNull(commandLine.getCommand());
       Expect::AreEqual(0, commandLine.getArguments().size());
       Expect::AreEqual(0, commandLine.getSettings().size());

       Assert::AreEqual(1, commandLine.getFlags().size());
       Assert::IsTrue(commandLine.hasFlag("-h"));
    }

    YW_TEST(CommandLine, WhenCommandLineIsProgramNameAndLongHelpFlagPFlagFieldISSet)
    {
        CommandLine commandLine{ "yw --help" };
        Expect::AreEqual("yw", commandLine.getProgram());
        Expect::IsNull(commandLine.getCommand());
        Expect::AreEqual(0, commandLine.getArguments().size());
        Expect::AreEqual(0, commandLine.getSettings().size());

        Assert::AreEqual(1, commandLine.getFlags().size());
		Assert::IsTrue(commandLine.hasFlag("--help"));
	}

    YW_TEST(CommandLine, WhenCommandLineIsProgramNameAndShortVersionFlagFlagFieldIsSet)
    {
        CommandLine commandLine{ "yw -v" };
        Expect::AreEqual("yw", commandLine.getProgram());
        Expect::IsNull(commandLine.getCommand());
        Expect::AreEqual(0, commandLine.getArguments().size());
        Expect::AreEqual(0, commandLine.getSettings().size());

        Assert::AreEqual(1, commandLine.getFlags().size());
		Assert::IsTrue(commandLine.hasFlag("-v"));
	}

    YW_TEST(CommandLine, WhenCommandLineIsProgramNameAndLongVersionFlagProgramAndPFlagFieldsAreSet)
    {
        CommandLine commandLine{ "yw --version" };
        Expect::AreEqual("yw", commandLine.getProgram());
        Expect::IsNull(commandLine.getCommand());
        Expect::AreEqual(0, commandLine.getArguments().size());
        Expect::AreEqual(0, commandLine.getSettings().size());

        Assert::AreEqual(1, commandLine.getFlags().size());
		Assert::IsTrue(commandLine.hasFlag("--version"));
	}

    YW_TEST(CommandLine, WhenCommandLineIncludesProgramNameTheProgramFieldIsSet)
    {
        CommandLine commandLine{ "yw graph" };
        Expect::AreEqual("yw", commandLine.getProgram());
        Expect::AreEqual(0, commandLine.getFlags().size());
        Expect::AreEqual(0, commandLine.getArguments().size());
        Expect::AreEqual(0, commandLine.getSettings().size());

        Assert::AreEqual("graph", commandLine.getCommand().getValue());
    }

    YW_TEST(CommandLine, WhenCommandLineIncludesOneArgumentTheArgumentsFieldContainsThatArgument)
    {
        CommandLine commandLine{ "yw graph myscript.py" };
        Expect::AreEqual("yw", commandLine.getProgram());
        Expect::AreEqual("graph", commandLine.getCommand().getValue());
        Expect::AreEqual(0, commandLine.getFlags().size());
        Expect::AreEqual(0, commandLine.getSettings().size());

        Assert::AreEqual(1, commandLine.getArguments().size());
        Assert::AreEqual("myscript.py", commandLine.getArguments()[0]);
    }

    YW_TEST(CommandLine, WhenCommandLineIncludesTwoArgumentsTheArgumentsFieldContainsBothArgument)
    {
        CommandLine commandLine{ "yw graph myscript.py another.py" };
        Expect::AreEqual("yw", commandLine.getProgram());
        Expect::AreEqual("graph", commandLine.getCommand().getValue());
        Expect::AreEqual(0, commandLine.getFlags().size());
        Expect::AreEqual(0, commandLine.getSettings().size());

        Assert::AreEqual(2, commandLine.getArguments().size());
        Assert::AreEqual("myscript.py", commandLine.getArguments()[0]);
        Assert::AreEqual("another.py", commandLine.getArguments()[1]);
    }

    YW_TEST(CommandLine, WhenCommandLineIncludesOneConfigOptionButNoCflagOptionIsInterpretedAsArgument)
    {
        CommandLine commandLine{ "yw graph myscript.py extract.volatile" };
        Expect::AreEqual("yw", commandLine.getProgram());
        Expect::AreEqual("graph", commandLine.getCommand().getValue());
        Expect::AreEqual(0, commandLine.getFlags().size());
        Expect::AreEqual(0, commandLine.getSettings().size());

        Assert::AreEqual(2, commandLine.getArguments().size());
        Assert::AreEqual("myscript.py", commandLine.getArguments()[0]);
        Assert::AreEqual("extract.volatile", commandLine.getArguments()[1]);
    }

    YW_TEST(CommandLine, WhenCommandLineIncludesOneConfigOptionFollowingCFlagConfigNameIsSetButConfigValueIsNull)
    {
        CommandLine commandLine{ "yw graph myscript.py -c extract.volatile" };
        Expect::AreEqual("yw", commandLine.getProgram());
        Expect::AreEqual("graph", commandLine.getCommand().getValue());
        Expect::AreEqual(0, commandLine.getFlags().size());

        Assert::AreEqual(1, commandLine.getArguments().size());
        Assert::AreEqual("myscript.py", commandLine.getArguments()[0]);
        Assert::AreEqual(1, commandLine.getSettings().size());
        Assert::IsTrue(commandLine.getSettings().contains("extract.volatile"));
        Assert::IsNull(commandLine.getSettings().getSetting("extract.volatile").valueText);
    }

    YW_TEST(CommandLine, WhenCommandLineIncludesOneConfigWithCFlagAndWithValueConfigNameAndConfigValueAreBothSet)
    {
        CommandLine commandLine{ "yw graph myscript.py -c extract.volatile=true" };
        Expect::AreEqual("yw", commandLine.getProgram());
        Expect::AreEqual("graph", commandLine.getCommand().getValue());
        Expect::AreEqual(0, commandLine.getFlags().size());

        Assert::AreEqual(1, commandLine.getArguments().size());
        Assert::AreEqual("myscript.py", commandLine.getArguments()[0]);
        Assert::AreEqual(1, commandLine.getSettings().size());
        Assert::AreEqual("true", commandLine.getSettings().getSetting("extract.volatile").valueText.getValue());
    }

    YW_TEST(CommandLine, WhenCommandLineIncludesOneConfigWithoutCFlagButWithValueConfigNameAndConfigValueAreBothSet)
    {
        CommandLine commandLine{ "yw graph myscript.py extract.volatile=true" };
        Expect::AreEqual("yw", commandLine.getProgram());
        Expect::AreEqual("graph", commandLine.getCommand().getValue());
        Expect::AreEqual(0, commandLine.getFlags().size());

        Assert::AreEqual(1, commandLine.getArguments().size());
        Assert::AreEqual("myscript.py", commandLine.getArguments()[0]);
        Assert::AreEqual(1, commandLine.getSettings().size());
        Assert::AreEqual("true", commandLine.getSettings().getSetting("extract.volatile").valueText.getValue());
    }

    YW_TEST(CommandLine, CommandLineCanAccomodateMultipleConfigOptionsWithAndWithoutValues)
    {
        CommandLine commandLine{ "yw graph myscript.py extract.volatile=true -c model.workflow=top graph.title='My workflow' --config graph.workflowbox" };
        Expect::AreEqual("yw", commandLine.getProgram());
        Expect::AreEqual("graph", commandLine.getCommand().getValue());
        Expect::AreEqual(0, commandLine.getFlags().size());
        Expect::AreEqual(1, commandLine.getArguments().size());
        Expect::AreEqual("myscript.py", commandLine.getArguments()[0]);

        Assert::AreEqual(4, commandLine.getSettings().size());
        Assert::AreEqual("true", commandLine.getSettings().getSetting("extract.volatile").valueText.getValue());
        Assert::AreEqual("top", commandLine.getSettings().getSetting("model.workflow").valueText.getValue());
        Assert::AreEqual("My workflow", commandLine.getSettings().getSetting("graph.title").valueText.getValue());
        Assert::IsTrue(commandLine.getSettings().contains("graph.workflowbox"));
        Assert::IsNull(commandLine.getSettings().getSetting("graph.workflowbox").valueText);
    }

    YW_TEST(CommandLine, CommandLineCanDistinguishInterleavedArgumentsAndConfigOptions)
    {
        CommandLine commandLine{ "yw graph arg1 extract.volatile=true arg2 -c model.workflow=top arg3 graph.title='My workflow' arg4 --config graph.workflowbox arg5" };
        Expect::AreEqual("yw", commandLine.getProgram());
        Expect::AreEqual("graph", commandLine.getCommand().getValue());
        Expect::AreEqual(0, commandLine.getFlags().size());

        Assert::AreEqual(5, commandLine.getArguments().size());
        Assert::AreEqual("arg1", commandLine.getArguments()[0]);
        Assert::AreEqual("arg2", commandLine.getArguments()[1]);
        Assert::AreEqual("arg3", commandLine.getArguments()[2]);
        Assert::AreEqual("arg4", commandLine.getArguments()[3]);
        Assert::AreEqual("arg5", commandLine.getArguments()[4]);
        Assert::AreEqual(4, commandLine.getSettings().size());
        Assert::AreEqual("true", commandLine.getSettings().getSetting("extract.volatile").valueText.getValue());
        Assert::AreEqual("top", commandLine.getSettings().getSetting("model.workflow").valueText.getValue());
        Assert::AreEqual("My workflow", commandLine.getSettings().getSetting("graph.title").valueText.getValue());
        Assert::IsTrue(commandLine.getSettings().contains("graph.workflowbox"));
        Assert::IsNull(commandLine.getSettings().getSetting("graph.workflowbox").valueText);
    }

YW_TEST_END
