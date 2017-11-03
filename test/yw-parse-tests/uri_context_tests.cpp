#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(UriContext)

    StderrRecorder stderrRecorder;

YW_TEST_SET

    YW_TEST(UriContext, ParsingUriKeywordAloneYieldsParseExceptionAndNullUriTemplate)
    {
        YWParserBuilder parser_builder("@uri");
        YWParser::UriContext* uri;
        try {
            uri = parser_builder.parse()->uri();
        }
        catch (yw::parse::ParsingException e) {
            Expect::AreEqual("A problem occurred parsing YW annotations.", e.getMessage());
        }     
        Expect::NonEmptyString(stderrRecorder.str());
        
        Assert::AreEqual("@uri", uri->UriKeyword()->getText());
        Assert::IsNull(uri->uriTemplate());
    }

    YW_TEST(UriContext, ParsingUriWithSingleWordArgumentYieldsNullSchemeAndWordAsPathTemplate)
    {
        YWParserBuilder parser_builder("@uri path");
        YWParser::UriContext* uri;
        uri = parser_builder.parse()->uri();
        Expect::AreEqual("", stderrRecorder.str());

        Assert::AreEqual("@uri", uri->UriKeyword()->getText());
        Assert::IsNull(uri->uriTemplate()->scheme());
        Assert::AreEqual("path", uri->uriTemplate()->pathTemplate()->getText());
    }

    YW_TEST(UriContext, ParsingUriWithSingleWordContainingADotYieldsNullSchemeAndWordAsPathTemplate)
    {
        YWParserBuilder parser_builder("@uri foo.txt");
        YWParser::UriContext* uri;
        uri = parser_builder.parse()->uri();
        Expect::AreEqual("", stderrRecorder.str());

        Assert::AreEqual("@uri", uri->UriKeyword()->getText());
        Assert::IsNull(uri->uriTemplate()->scheme());
        Assert::AreEqual("foo.txt", uri->uriTemplate()->pathTemplate()->getText());
    }

    YW_TEST(UriContext, ParsingUriWithSingleSlashAndSingleWordArgumentYieldsNullSchemeAndWordWithSingleStartingSlashAsPathTemplate)
    {
        YWParserBuilder parser_builder("@uri /path");
        YWParser::UriContext* uri;
        uri = parser_builder.parse()->uri();
        Expect::AreEqual("", stderrRecorder.str());

        Assert::AreEqual("@uri", uri->UriKeyword()->getText());
        Assert::IsNull(uri->uriTemplate()->scheme());
        Assert::AreEqual("/path", uri->uriTemplate()->pathTemplate()->getText());
    }

    YW_TEST(UriContext, ParsingUriWithDoubleSlashAndSingleWordArgumentYieldsNullSchemeAndWordWithSingleStartingSlashAsPathTemplate)
    {
        YWParserBuilder parser_builder("@uri //path");
        YWParser::UriContext* uri;
        uri = parser_builder.parse()->uri();
        Expect::AreEqual("", stderrRecorder.str());

        Assert::AreEqual("@uri", uri->UriKeyword()->getText());
        Assert::IsNull(uri->uriTemplate()->scheme());
        Assert::AreEqual("//path", uri->uriTemplate()->pathTemplate()->getText());
    }

    YW_TEST(UriContext, ParsingUriWithTripleSlashAndSingleWordArgumentYieldsNullSchemeAndWordWithSingleStartingSlashAsPathTemplate)
    {
        YWParserBuilder parser_builder("@uri //path");
        YWParser::UriContext* uri;
        uri = parser_builder.parse()->uri();
        Expect::AreEqual("", stderrRecorder.str());

        Assert::AreEqual("@uri", uri->UriKeyword()->getText());
        Assert::IsNull(uri->uriTemplate()->scheme());
        Assert::AreEqual("//path", uri->uriTemplate()->pathTemplate()->getText());
    }

    YW_TEST(UriContext, ParsingUriWithSimplePathArgumentYieldsNullSchemeAndPathAsPathTemplate)
    {
        YWParserBuilder parser_builder("@uri /a/simple/path");
        YWParser::UriContext* uri;
        uri = parser_builder.parse()->uri();
        Expect::AreEqual("", stderrRecorder.str());

        Assert::AreEqual("@uri", uri->UriKeyword()->getText());
        Assert::IsNull(uri->uriTemplate()->scheme());
        Assert::AreEqual("/a/simple/path", uri->uriTemplate()->pathTemplate()->getText());
    }

    YW_TEST(UriContext, ParsingUriWithPathArgumentWithDotsInPathElementsYieldsNullSchemeAndPathAsPathTemplate)
    {
        YWParserBuilder parser_builder("@uri /a.dir/simple.dir/foo.txt");
        YWParser::UriContext* uri;
        uri = parser_builder.parse()->uri();
        Expect::AreEqual("", stderrRecorder.str());

        Assert::AreEqual("@uri", uri->UriKeyword()->getText());
        Assert::IsNull(uri->uriTemplate()->scheme());
        Assert::AreEqual("/a.dir/simple.dir/foo.txt", uri->uriTemplate()->pathTemplate()->getText());
    }

    YW_TEST(UriContext, ParsingUriWithSchemeSingleLeadingSlashAndPathWithDotsInPathElementsYieldsNullSchemeAndPathAsPathTemplate)
    {
        YWParserBuilder parser_builder("@uri file:/a.dir/simple.dir/foo.txt");
        YWParser::UriContext* uri;
        uri = parser_builder.parse()->uri();
        Expect::AreEqual("", stderrRecorder.str());

        Assert::AreEqual("@uri", uri->UriKeyword()->getText());
        Assert::AreEqual("file", uri->uriTemplate()->scheme()->getText());
        Assert::AreEqual("/a.dir/simple.dir/foo.txt", uri->uriTemplate()->pathTemplate()->getText());
    }

    YW_TEST(UriContext, ParsingUriWithSchemeTwoLeadingSlashesAndPathWithDotsInPathElementsYieldsNullSchemeAndPathAsPathTemplate)
    {
        YWParserBuilder parser_builder("@uri file://a.dir/simple.dir/foo.txt");
        YWParser::UriContext* uri;
        uri = parser_builder.parse()->uri();
        Expect::AreEqual("", stderrRecorder.str());

        Expect::AreEqual("", stderrRecorder.str());
        Assert::AreEqual("@uri", uri->UriKeyword()->getText());
        Assert::AreEqual("file", uri->uriTemplate()->scheme()->getText());
        Assert::AreEqual("//a.dir/simple.dir/foo.txt", uri->uriTemplate()->pathTemplate()->getText());
    }

    YW_TEST(UriContext, ParsingUriWithSimplePathArgumentStartingWithDoubleSlashYieldsPathWithSingleStartingSlash)
    {
        YWParserBuilder parser_builder("@uri //a/simple/path");
        YWParser::UriContext* uri;
        uri = parser_builder.parse()->uri();
        Expect::AreEqual("", stderrRecorder.str());

        Assert::AreEqual("@uri", uri->UriKeyword()->getText());
        Assert::IsNull(uri->uriTemplate()->scheme());
        Assert::AreEqual("//a/simple/path", uri->uriTemplate()->pathTemplate()->getText());
    }

    YW_TEST(UriContext, ParsingUriWithSchemeColonAndSinglePathElementYieldsSchemeAndPath)
    {
        YWParserBuilder parser_builder("@uri http:path");
        YWParser::UriContext* uri;
        uri = parser_builder.parse()->uri();
        Expect::AreEqual("", stderrRecorder.str());

        Assert::AreEqual("@uri", uri->UriKeyword()->getText());
        Assert::AreEqual("http", uri->uriTemplate()->scheme()->getText());
        Assert::AreEqual("path", uri->uriTemplate()->pathTemplate()->getText());
    }

    YW_TEST(UriContext, ParsingUriWithSchemeColonSlashAndSinglePathElementYieldsSchemeAndPathWithSingleInitialSlash)
    {
        YWParserBuilder parser_builder("@uri http:/path");
        YWParser::UriContext* uri;
        uri = parser_builder.parse()->uri();
        Expect::AreEqual("", stderrRecorder.str());

        Assert::AreEqual("@uri", uri->UriKeyword()->getText());
        Assert::AreEqual("http", uri->uriTemplate()->scheme()->getText());
        Assert::AreEqual("/path", uri->uriTemplate()->pathTemplate()->getText());
    }


    YW_TEST(UriContext, ParsingUriWithSchemeColonDoubleSlashAndSinglePathElementYieldsSchemeAndPathWithSingleInitialSlash)
    {
        YWParserBuilder parser_builder("@uri http://path");
        YWParser::UriContext* uri;
        uri = parser_builder.parse()->uri();
        Expect::AreEqual("", stderrRecorder.str());

        Assert::AreEqual("@uri", uri->UriKeyword()->getText());
        Assert::AreEqual("http", uri->uriTemplate()->scheme()->getText());
        Assert::AreEqual("//path", uri->uriTemplate()->pathTemplate()->getText());
    }

    YW_TEST(UriContext, ParsingUriWithSchemeColonTripleSlashAndSinglePathElementYieldsSchemeAndPathWithSingleInitialSlash)
    {
        YWParserBuilder parser_builder("@uri http://path");
        YWParser::UriContext* uri;
        uri = parser_builder.parse()->uri();
        Expect::AreEqual("", stderrRecorder.str());

        Assert::AreEqual("@uri http://path", uri->getText());
        Assert::AreEqual("@uri", uri->UriKeyword()->getText());
        Assert::AreEqual("http", uri->uriTemplate()->scheme()->getText());
        Assert::AreEqual("//path", uri->uriTemplate()->pathTemplate()->getText());
    }

    YW_TEST(UriContext, ParsingUriWithSchemeAndDoubleSlashOnlySchemeAndPathOfSingleSlash)
    {
        YWParserBuilder parser_builder("@uri file://");
        YWParser::UriContext* uri;
        uri = parser_builder.parse()->uri();
        Expect::AreEqual("", stderrRecorder.str());

        Assert::AreEqual("@uri", uri->UriKeyword()->getText());
        Assert::AreEqual("file", uri->uriTemplate()->scheme()->getText());
        Assert::AreEqual("//", uri->uriTemplate()->pathTemplate()->getText());
    }

    YW_TEST(UriContext, ParsingUriWithSimpleUrlYieldsCorrectSchemeAndPath)
    {
        YWParserBuilder parser_builder("@uri http://foo.org/bar.txt");
        YWParser::UriContext* uri;
        uri = parser_builder.parse()->uri();
        Expect::AreEqual("", stderrRecorder.str());

        //Assert::AreEqual("http://foo.org/bar.txt", uri->getText());
        Assert::AreEqual("@uri", uri->UriKeyword()->getText());
        Assert::AreEqual("http", uri->uriTemplate()->scheme()->getText());
        Assert::AreEqual("//foo.org/bar.txt", uri->uriTemplate()->pathTemplate()->getText());
    }

YW_TEST_END