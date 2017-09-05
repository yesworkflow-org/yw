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

    YW_TEST(CommandLineContext, WhenCommandLineIsJustProgramNameAndShortHelpFlagProgramAndCflagFieldsAreSet)
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

    YW_TEST(CommandLineContext, WhenCommandLineIsJustProgramNameAndLongHelpFlagProgramAndPFlagFieldsAreSet)
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

    YW_TEST(CommandLineContext, WhenCommandLineIsJustProgramNameAndShortVersionFlagProgramAndPFlagFieldsAreSet)
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

    YW_TEST(CommandLineContext, WhenCommandLineIsJustProgramNameAndLongVersionFlagProgramAndPFlagFieldsAreSet)
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

YW_TEST_END
