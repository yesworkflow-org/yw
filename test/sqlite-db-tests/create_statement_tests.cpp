#include "sqlite_db_tests.h"

using namespace yw::test;
using namespace yw::sqlite;

YW_TEST_FIXTURE(CreateStatement)

    SQLiteDB db;

YW_TEST_SET

    YW_TEST(CreateStatement, ValidStatementConstructsSuccessfully)
    {
        CreateStatement statement(db, R"(
            CREATE TABLE user(
                id                  INTEGER         NOT NULL        PRIMARY KEY,
                name                TEXT            NULL
            );
        )");
    }

    YW_TEST(CreateStatement, StatementWithCommaAfterLastColumnThrowsPreparationException)
    {
        try {
            CreateStatement statement(db, R"(
                CREATE TABLE user(
                    id                  INTEGER         NOT NULL        PRIMARY KEY,
                    name                TEXT            NULL,
                );
            )");
            Assert::Fail();
        }
        catch (PreparationException& e) {
            Assert::AreEqual(R"<>(Error preparing statement: near ")": syntax error)<>", e.getMessage());
        }
    }

    YW_TEST(CreateStatement, StatementWithMissingCommaBetweenColumnsThrowsPreparationException)
    {
        try {
            CreateStatement statement(db, R"(
                CREATE TABLE user(
                    id                  INTEGER         NOT NULL        PRIMARY KEY
                    name                TEXT            NULL
                );
            )");
            Assert::Fail();
        }
        catch (PreparationException& e) {
            Assert::AreEqual(R"<>(Error preparing statement: near "name": syntax error)<>", e.getMessage());
        }
    }

    YW_TEST(CreateStatement, TestCreateStatement_Execute_SingleTable)
    {
        CreateStatement createUser(db, R"(
            CREATE TABLE user(
                id                  INTEGER         NOT NULL        PRIMARY KEY,
                name                TEXT            NULL
            );
        )");
        createUser.execute();
    }

    YW_TEST(CreateStatement, TestCreateStatement_Execute_TwoTables)
    {
        CreateStatement createUser(db, R"(
            CREATE TABLE user(
                id                  INTEGER         NOT NULL        PRIMARY KEY,
                name                TEXT            NULL
            );
        )");
        CreateStatement createFile(db, R"(
            CREATE TABLE file(
                id                  INTEGER         NOT NULL        PRIMARY KEY,
                filename            TEXT            NULL
            );
        )");
        createUser.execute();
        createFile.execute();
    }

    YW_TEST(CreateStatement, TestCreateStatement_Execute_TwoTables_ValidReference)
    {
        CreateStatement createUser(db, R"(
            CREATE TABLE user(
                id                  INTEGER         NOT NULL        PRIMARY KEY,
                name                TEXT            NULL
            );
        )");
        CreateStatement createFile(db, R"(
            CREATE TABLE file(
                id                  INTEGER         NOT NULL        PRIMARY KEY,
                filename            TEXT            NULL,
                owner               INTEGER         NOT NULL        REFERENCES user(id)
            );
        )");
        createUser.execute();
        createFile.execute();
    }

    YW_TEST(CreateStatement, TestCreateStatement_Execute_TwoTables_InvalidReference)
    {
        CreateStatement createUser(db, R"(
            CREATE TABLE user(
                id                  INTEGER         NOT NULL        PRIMARY KEY,
                name                TEXT            NULL
            );
        )");
        createUser.execute();

        CreateStatement createFile(db, R"(
            CREATE TABLE file(
                id                  INTEGER         NOT NULL        PRIMARY KEY,
                filename            TEXT            NOT NULL,
                user                INTEGER         NOT NULL        REFERENCES user(id)
            );
        )");
        createFile.execute();

        try {
            InsertStatement statement(db, "INSERT INTO file(filename, user) VALUES (?,?);");
            statement.bindText(1, "script.sh");
            statement.bindInt64(2, 1);
            statement.execute();
            Assert::Fail();
        }
        catch (InsertException e) {
            Assert::AreEqual("Error inserting row into table: FOREIGN KEY constraint failed", 
                e.getMessage());
            Assert::AreEqual("abort at 14 in [INSERT INTO file(filename, user) VALUES (?,?);]: FOREIGN KEY constraint failed",
                e.getDetails());
        }
    }

YW_TEST_END
