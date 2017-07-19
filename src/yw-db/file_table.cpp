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
					name                TEXT            NOT NULL

					/*
					fs_file_id          INTEGER         NULL,
					fs_device_id        INTEGER         NULL,
					fs_path             TEXT            NULL,
					fs_owner_id         INTEGER         NULL,
					fs_create_date      TEXT            NULL,
					fs_modify_date      TEXT            NULL,
					size                INTEGER         NULL,       
					hash                INTEGER         NULL
					*/

				);

			)"));
		}

		long YesWorkflowDB::insert(const FileRow& file) {
            string sql = "INSERT INTO file(id, name) VALUES (?,?);";
            InsertStatement statement(db, sql);
			statement.bindNullableId(1, file.id);
			statement.bindText(2, file.name);
            statement.execute();
            return statement.getGeneratedId();
        }

        FileRow YesWorkflowDB::selectFileById(long requested_id) {
            string sql = "SELECT id, name FROM file WHERE id = ?";
            SelectStatement statement(db, sql);
            statement.bindInt64(1, requested_id);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No row with that id");
            auto id = statement.getNullableIdField(0);
            auto name = statement.getTextField(1);
			return FileRow{ id, name };
        }
    }
}