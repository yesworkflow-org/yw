#include "yw_cli_tests.h"

using namespace yw;
using namespace yw::cli;
using namespace yw::test;

YW_TEST_FIXTURE(BeginContext)

    StderrRecorder stderrRecorder;

YW_TEST_SET

   YW_TEST(CommandLineContext, WhenCommandLineIsJustProgramNameProgramFieldIsSet)
    {
        YW_CLI_ParserBuilder parser_builder("yw");
        YW_CLI_Parser::CommandLineContext* context = parser_builder.parse()->commandLine();
        Expect::EmptyString(stderrRecorder.str());

        Expect::AreEqual(0, context->pflag().size());
        Expect::IsNull(context->command());
        Expect::AreEqual(0, context->argument().size());
        Expect::AreEqual(0, context->config().size());

        Assert::AreEqual("yw", context->program()->getText());
    }

    YW_TEST(CommandLineContext, WhenCommandLineIsProgramNameAndShortHelpFlagProgramAndCflagFieldsAreSet)
    {
        YW_CLI_ParserBuilder parser_builder("yw -h");
        YW_CLI_Parser::CommandLineContext* context = parser_builder.parse()->commandLine();
        Expect::EmptyString(stderrRecorder.str());

        Expect::IsNull(context->command());
        Expect::AreEqual(0, context->argument().size());
        Expect::AreEqual(0, context->config().size());

        Assert::AreEqual("yw", context->program()->getText());
        Assert::AreEqual(1, context->pflag().size());
        Assert::AreEqual("-h", context->pflag()[0]->getText());
        Assert::IsNotNull(context->pflag()[0]->helpflag());
        Assert::IsNull(context->pflag()[0]->versionflag());
    }

    YW_TEST(CommandLineContext, WhenCommandLineIsProgramNameAndLongHelpFlagProgramAndPFlagFieldsAreSet)
    {
        YW_CLI_ParserBuilder parser_builder("yw --help");
        YW_CLI_Parser::CommandLineContext* context = parser_builder.parse()->commandLine();
        Expect::EmptyString(stderrRecorder.str());

        Expect::IsNull(context->command());
        Expect::AreEqual(0, context->argument().size());
        Expect::AreEqual(0, context->config().size());

        Assert::AreEqual("yw", context->program()->getText());
        Assert::AreEqual(1, context->pflag().size());
        Assert::AreEqual("--help", context->pflag()[0]->getText());
        Assert::IsNotNull(context->pflag()[0]->helpflag());
        Assert::IsNull(context->pflag()[0]->versionflag());
    }

    YW_TEST(CommandLineContext, WhenCommandLineIsProgramNameAndShortVersionFlagProgramAndPFlagFieldsAreSet)
    {
        YW_CLI_ParserBuilder parser_builder("yw -v");
        YW_CLI_Parser::CommandLineContext* context = parser_builder.parse()->commandLine();
        Expect::EmptyString(stderrRecorder.str());

        Expect::IsNull(context->command());
        Expect::AreEqual(0, context->argument().size());
        Expect::AreEqual(0, context->config().size());

        Assert::AreEqual("yw", context->program()->getText());
        Assert::AreEqual(1, context->pflag().size());
        Assert::AreEqual("-v", context->pflag()[0]->getText());
        Assert::IsNotNull(context->pflag()[0]->versionflag());
        Assert::IsNull(context->pflag()[0]->helpflag());
    }

    YW_TEST(CommandLineContext, WhenCommandLineIsProgramNameAndLongVersionFlagProgramAndPFlagFieldsAreSet)
    {
        YW_CLI_ParserBuilder parser_builder("yw --version");
        YW_CLI_Parser::CommandLineContext* context = parser_builder.parse()->commandLine();
        Expect::EmptyString(stderrRecorder.str());

        Expect::IsNull(context->command());
        Expect::AreEqual(0, context->argument().size());
        Expect::AreEqual(0, context->config().size());

        Assert::AreEqual("yw", context->program()->getText());
        Assert::AreEqual(1, context->pflag().size());
        Assert::AreEqual("--version", context->pflag()[0]->getText());
        Assert::IsNotNull(context->pflag()[0]->versionflag());
        Assert::IsNull(context->pflag()[0]->helpflag());
    }

    YW_TEST(CommandLineContext, WhenCommandLineIncludesProgramNameTheProgramFieldIsSet)
    {
        YW_CLI_ParserBuilder parser_builder("yw graph");
        YW_CLI_Parser::CommandLineContext* context = parser_builder.parse()->commandLine();
        Expect::EmptyString(stderrRecorder.str());

        Expect::AreEqual(0, context->pflag().size());
        Expect::AreEqual(0, context->argument().size());
        Expect::AreEqual(0, context->config().size());
        Expect::AreEqual("yw", context->program()->getText());

        Assert::AreEqual("graph", context->command()->getText());
    }

    YW_TEST(CommandLineContext, WhenCommandLineIncludesOneArgumentTheArgumentsFieldContainsThatArgument)
    {
        YW_CLI_ParserBuilder parser_builder("yw graph myscript.py");
        YW_CLI_Parser::CommandLineContext* context = parser_builder.parse()->commandLine();
        Expect::EmptyString(stderrRecorder.str());

        Expect::AreEqual(0, context->pflag().size());
        Expect::AreEqual(0, context->config().size());
        Expect::AreEqual("yw", context->program()->getText());
        Expect::AreEqual("graph", context->command()->getText());

        Assert::AreEqual(1, context->argument().size());
        Assert::AreEqual("myscript.py", context->argument()[0]->getText());
    }

    YW_TEST(CommandLineContext, WhenCommandLineIncludesTwoArgumentsTheArgumentsFieldContainsBothArgument)
    {
        YW_CLI_ParserBuilder parser_builder("yw graph myscript.py another.py");
        YW_CLI_Parser::CommandLineContext* context = parser_builder.parse()->commandLine();
        Expect::EmptyString(stderrRecorder.str());

        Expect::AreEqual(0, context->pflag().size());
        Expect::AreEqual(0, context->config().size());
        Expect::AreEqual("yw", context->program()->getText());
        Expect::AreEqual("graph", context->command()->getText());

        Assert::AreEqual(2, context->argument().size());
        Assert::AreEqual("myscript.py", context->argument()[0]->getText());
        Assert::AreEqual("another.py", context->argument()[1]->getText());
    }

    YW_TEST(CommandLineContext, WhenCommandLineIncludesOneConfigOptionButNoCflagOptionIsInterpretedAsArgument)
    {
        YW_CLI_ParserBuilder parser_builder("yw graph myscript.py extract.volatile");
        YW_CLI_Parser::CommandLineContext* context = parser_builder.parse()->commandLine();
        Expect::EmptyString(stderrRecorder.str());

        Expect::AreEqual(0, context->pflag().size());
        Expect::AreEqual(0, context->config().size());
        Expect::AreEqual("yw", context->program()->getText());
        Expect::AreEqual("graph", context->command()->getText());

        Assert::AreEqual(2, context->argument().size());
        Assert::AreEqual("myscript.py", context->argument()[0]->getText());
        Assert::AreEqual("extract.volatile", context->argument()[1]->getText());
    }


    YW_TEST(CommandLineContext, WhenCommandLineIncludesOneConfigOptionFollowingCFlagConfigNameIsSetButConfigValueIsNull)
    {
        YW_CLI_ParserBuilder parser_builder("yw graph myscript.py -c extract.volatile");
        YW_CLI_Parser::CommandLineContext* context = parser_builder.parse()->commandLine();
        Expect::EmptyString(stderrRecorder.str());

        Expect::AreEqual(0, context->pflag().size());
        Expect::AreEqual("yw", context->program()->getText());
        Expect::AreEqual("graph", context->command()->getText());
        Expect::AreEqual(1, context->argument().size());
        Expect::AreEqual("myscript.py", context->argument()[0]->getText());

        Assert::AreEqual(1, context->config().size());
        Assert::AreEqual("extract.volatile", context->config()[0]->configName()->getText());
        Assert::IsNull(context->config()[0]->configValue());
    }

    YW_TEST(CommandLineContext, WhenCommandLineIncludesOneConfigWithCFlagAndWithValueConfigNameAndConfigValueAreBothSet)
    {
        YW_CLI_ParserBuilder parser_builder("yw graph myscript.py -c extract.volatile=true");
        YW_CLI_Parser::CommandLineContext* context = parser_builder.parse()->commandLine();
        Expect::EmptyString(stderrRecorder.str());

        Expect::AreEqual(0, context->pflag().size());
        Expect::AreEqual("yw", context->program()->getText());
        Expect::AreEqual("graph", context->command()->getText());
        Expect::AreEqual(1, context->argument().size());
        Expect::AreEqual("myscript.py", context->argument()[0]->getText());

        Assert::AreEqual(1, context->config().size());
        Assert::AreEqual("extract.volatile", context->config()[0]->configName()->getText());
        Assert::AreEqual("true", context->config()[0]->configValue()->getText());
    }

    YW_TEST(CommandLineContext, WhenCommandLineIncludesOneConfigWithoutCFlagButWithValueConfigNameAndConfigValueAreBothSet)
    {
        YW_CLI_ParserBuilder parser_builder("yw graph myscript.py extract.volatile=true");
        YW_CLI_Parser::CommandLineContext* context = parser_builder.parse()->commandLine();
        Expect::EmptyString(stderrRecorder.str());

        Expect::AreEqual(0, context->pflag().size());
        Expect::AreEqual("yw", context->program()->getText());
        Expect::AreEqual("graph", context->command()->getText());
        Expect::AreEqual(1, context->argument().size());
        Expect::AreEqual("myscript.py", context->argument()[0]->getText());

        Assert::AreEqual(1, context->config().size());
        Assert::AreEqual("extract.volatile", context->config()[0]->configName()->getText());
        Assert::AreEqual("true", context->config()[0]->configValue()->getText());
    }

    YW_TEST(CommandLineContext, CommandLineCanAccomodateMultipleConfigOptionsWithAndWithoutValues)
    {
        YW_CLI_ParserBuilder parser_builder("yw graph myscript.py extract.volatile=true -c model.workflow=top graph.title='My workflow' --config graph.workflowbox");
        YW_CLI_Parser::CommandLineContext* context = parser_builder.parse()->commandLine();
        Expect::EmptyString(stderrRecorder.str());

        Expect::AreEqual(0, context->pflag().size());
        Expect::AreEqual("yw", context->program()->getText());
        Expect::AreEqual("graph", context->command()->getText());
        Expect::AreEqual(1, context->argument().size());
        Expect::AreEqual("myscript.py", context->argument()[0]->getText());

        Assert::AreEqual( 4, context->config().size());
        Assert::AreEqual("extract.volatile", context->config()[0]->configName()->getText());
        Assert::AreEqual("true", context->config()[0]->configValue()->getText());
        Assert::AreEqual("model.workflow", context->config()[1]->configName()->getText());
        Assert::AreEqual("top", context->config()[1]->configValue()->getText());
        Assert::AreEqual("graph.title", context->config()[2]->configName()->getText());
        Assert::AreEqual("'My workflow'", context->config()[2]->configValue()->getText());
        Assert::AreEqual("graph.workflowbox", context->config()[3]->configName()->getText());
        Assert::IsNull(context->config()[3]->configValue());
    }

    YW_TEST(CommandLineContext, CommandLineCanDistinguishInterleavedArgumentsAndConfigOptions)
    {
        YW_CLI_ParserBuilder parser_builder("yw graph arg1 extract.volatile=true arg2 -c model.workflow=top arg3 graph.title='My workflow' arg4 --config graph.workflowbox arg5");
        YW_CLI_Parser::CommandLineContext* context = parser_builder.parse()->commandLine();
        Expect::EmptyString(stderrRecorder.str());

        Expect::AreEqual(0, context->pflag().size());
        Expect::AreEqual("yw", context->program()->getText());
        Expect::AreEqual("graph", context->command()->getText());

        Assert::AreEqual(5, context->argument().size());
        Assert::AreEqual("arg1", context->argument()[0]->getText());
        Assert::AreEqual("arg2", context->argument()[1]->getText());
        Assert::AreEqual("arg3", context->argument()[2]->getText());
        Assert::AreEqual("arg4", context->argument()[3]->getText());
        Assert::AreEqual("arg5", context->argument()[4]->getText());
        Assert::AreEqual(4, context->config().size());
        Assert::AreEqual("extract.volatile", context->config()[0]->configName()->getText());
        Assert::AreEqual("true", context->config()[0]->configValue()->getText());
        Assert::AreEqual("model.workflow", context->config()[1]->configName()->getText());
        Assert::AreEqual("top", context->config()[1]->configValue()->getText());
        Assert::AreEqual("graph.title", context->config()[2]->configName()->getText());
        Assert::AreEqual("'My workflow'", context->config()[2]->configValue()->getText());
        Assert::AreEqual("graph.workflowbox", context->config()[3]->configName()->getText());
        Assert::IsNull(context->config()[3]->configValue());
    }

YW_TEST_END
