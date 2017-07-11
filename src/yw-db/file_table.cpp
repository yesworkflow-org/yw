#include "yesworkflow_db.h"
#include "insert_statement.h"
#include "select_statement.h"

using namespace yw::sqlite;
using std::string;

namespace yw {
    namespace db {

		void YesWorkflowDB::createFileTable() {
			SQLiteDB::createTable(db, std::string(R"(

				CREATE TABLE file(
					id                  INTEGER         NOT NULL        PRIMARY KEY,
					name                TEXT            NOT NULL,
					owner               INTEGER         NULL            REFERENCES user(id),
					fs_file_id          INTEGER         NULL,
					fs_device_id        INTEGER         NULL,
					fs_path             TEXT            NULL,
					fs_owner_id         INTEGER         NULL,
					fs_create_date      TEXT            NULL,
					fs_modify_date      TEXT            NULL,
					size                INTEGER         NULL,       
					hash                INTEGER         NULL
				);

			)"));
		}

        long YesWorkflowDB::insertFile(const string& name, long owner) {
            string sql = "INSERT INTO file(name, owner) VALUES (?,?);";
            InsertStatement statement(db, sql);
            statement.bindText(1, name);
            statement.bindInt64(2, owner);
            statement.execute();
            return statement.getGeneratedId();
        }

        FileRow YesWorkflowDB::selectFileById(long requested_id) {
            string sql = "SELECT id, name, owner FROM file WHERE id = ?";
            SelectStatement statement(db, sql);
            statement.bindInt64(1, requested_id);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No row with that id");
            auto id = statement.getInt64Field(0);
            auto name = statement.getTextField(1);
            auto owner = statement.getInt64Field(2);
            return FileRow(id, name, owner);
        }
    }
}