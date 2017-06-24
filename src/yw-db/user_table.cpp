#include "yesworkflow_db.h"

using std::string;
using namespace yw::sqlite;

namespace yw {
    namespace db {

        long YesWorkflowDB::insertUser(const string& name) {
            string sql = "INSERT INTO user(name) VALUES (?);";
            SQLiteStatement statement(db, sql);
            statement.bindText(1, name);
            statement.step();
            return statement.getGeneratedId();
        }

        UserRow YesWorkflowDB::selectUserById(long requested_id) {
            string sql = "SELECT id, name FROM user WHERE id = ?";
            SQLiteStatement statement(db, sql);
            statement.bindInt64(1, requested_id);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No row with that id");
            auto id = statement.getInt64Field(0);
            auto name = statement.getTextField(1);
            return UserRow(id, name);
        }
    }
}