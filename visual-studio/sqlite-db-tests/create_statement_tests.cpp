#include "common_includes.h"

using namespace yw::test;

namespace yw {
    namespace sqlite {

        TEST_CLASS(CreateStatementTests)
        {
        public:

            TEST_METHOD(TestCreateStatement_Constructor_ValidStatement)
            {
                SQLiteDB db;
                CreateStatement statement(db, R"(
                    CREATE TABLE user(
                        id                  INTEGER         NOT NULL        PRIMARY KEY,
                        name                TEXT            NULL
                    );
                )");
            }

            TEST_METHOD(TestCreateStatement_Constructor_InvalidStatement_CommaAfterLastColumn)
            {
                SQLiteDB db;
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

            TEST_METHOD(TestCreateStatement_Constructor_InvalidStatement_MissingCommaBetweenColumns)
            {
                SQLiteDB db;
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

            TEST_METHOD(TestCreateStatement_Execute_SingleTable)
            {
                SQLiteDB db;
                CreateStatement createUser(db, R"(
                    CREATE TABLE user(
                        id                  INTEGER         NOT NULL        PRIMARY KEY,
                        name                TEXT            NULL
                    );
                )");
                createUser.execute();
            }

            TEST_METHOD(TestCreateStatement_Execute_TwoTables)
            {
                SQLiteDB db;
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

            TEST_METHOD(TestCreateStatement_Execute_TwoTables_ValidReference)
            {
                SQLiteDB db;
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

            TEST_METHOD(TestCreateStatement_Execute_TwoTables_InvalidReference)
            {
                SQLiteDB db;
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
        };
    }
}