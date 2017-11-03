#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(FileContext)

    StderrRecorder stderrRecorder;

YW_TEST_SET

    YW_TEST(FileContext, ParsingFileKeywordAloneYieldsParseExceptionAndNullpathTemplate)
    {
        YWParserBuilder parser_builder("@file");
        YWParser::FileContext* file;
        try {
            file = parser_builder.parse()->file();
        }
        catch (yw::parse::ParsingException e) {
            Expect::AreEqual("A problem occurred parsing YW annotations.", e.getMessage());
        }
        
        Assert::AreEqual("@file", file->FileKeyword()->getText());
        Assert::IsNull(file->pathTemplate());
    }

    YW_TEST(FileContext, ParsingFileWithSingleWordArgumentYieldsNullSchemeAndWordAsPathTemplate)
    {
        YWParserBuilder parser_builder("@file path");
        YWParser::FileContext* file;
        file = parser_builder.parse()->file();

        Assert::AreEqual("@file", file->FileKeyword()->getText());
        Assert::AreEqual("path", file->pathTemplate()->getText());
    }

    YW_TEST(FileContext, ParsingFileWithDotContainingSingleWordArgumentYieldsNullSchemeAndWordAsPathTemplate)
    {
        YWParserBuilder parser_builder("@file foo.txt");
        YWParser::FileContext* file;
        file = parser_builder.parse()->file();

        Assert::AreEqual("@file", file->FileKeyword()->getText());
        Assert::AreEqual("foo.txt", file->pathTemplate()->getText());
    }

    YW_TEST(FileContext, ParsingfileWithSingleSlashAndSingleWordArgumentYieldsNullSchemeAndWordWithSingleStartingSlashAsPathTemplate)
    {
        YWParserBuilder parser_builder("@file /path");
        YWParser::FileContext* file;
        file = parser_builder.parse()->file();

        Assert::AreEqual("@file", file->FileKeyword()->getText());
        Assert::AreEqual("/path", file->pathTemplate()->getText());
    }

    YW_TEST(FileContext, ParsingfileWithDoubleSlashAndSingleWordArgumentYieldsNullSchemeAndWordWithSingleStartingSlashAsPathTemplate)
    {
        YWParserBuilder parser_builder("@file //path");
        YWParser::FileContext* file;
        file = parser_builder.parse()->file();

        Assert::AreEqual("@file", file->FileKeyword()->getText());
        Assert::AreEqual("//path", file->pathTemplate()->getText());
    }

    YW_TEST(FileContext, ParsingfileWithSimplePathArgumentYieldsNullSchemeAndPathAsPathTemplate)
    {
        YWParserBuilder parser_builder("@file /a/simple/path");
        YWParser::FileContext* file;
        file = parser_builder.parse()->file();

        Assert::AreEqual("@file", file->FileKeyword()->getText());
        Assert::AreEqual("/a/simple/path", file->pathTemplate()->getText());
    }

    YW_TEST(FileContext, ParsingfileWithPathArgumentContainingDotsInPathElementsYieldsNullSchemeAndPathAsPathTemplate)
    {
        YWParserBuilder parser_builder("@file /a.dir/simple.dir/path.txt");
        YWParser::FileContext* file;
        file = parser_builder.parse()->file();

        Assert::AreEqual("@file", file->FileKeyword()->getText());
        Assert::AreEqual("/a.dir/simple.dir/path.txt", file->pathTemplate()->getText());
    }


    YW_TEST(FileContext, ParsingfileWithSimplePathArgumentStartingWithDoubleSlashYieldsPathWithSingleStartingSlash)
    {
        YWParserBuilder parser_builder("@file //a/simple/path");
        YWParser::FileContext* file;
        file = parser_builder.parse()->file();

        Assert::AreEqual("@file", file->FileKeyword()->getText());
        Assert::AreEqual("//a/simple/path", file->pathTemplate()->getText());
    }

    YW_TEST(FileContext, ParsingfileWithSimpleUrlYieldsCorrectSchemeAndPath)
    {
        YWParserBuilder parser_builder("@file /foo.org/bar.txt");
        YWParser::FileContext* file;
        file = parser_builder.parse()->file();

        Assert::AreEqual("@file", file->FileKeyword()->getText());
        Assert::AreEqual("/foo.org/bar.txt", file->pathTemplate()->getText());
    }

YW_TEST_END