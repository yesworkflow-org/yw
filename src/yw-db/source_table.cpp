#include "yw_db.h"

using std::string;

namespace yw_db {
    
    sqlite3_int64 YesWorkflowDB::insertSource(const string& path) {
        string sql = "INSERT INTO source(path) VALUES (?);";
        SQLiteStatement statement(db, sql);
        statement.bindText(1, path);
        statement.step();
        return sqlite3_last_insert_rowid(db);
    }

    SourceRow YesWorkflowDB::selectSourceById(long requested_id) {
        string sql = "SELECT id, path FROM source WHERE id = ?";
        SQLiteStatement statement(db, sql);
        statement.bindInt64(1, requested_id);
        if (statement.step() != SQLITE_ROW) throw std::runtime_error("No row with that id");
        auto id = statement.getInt64Field(0);
        auto path = statement.getTextField(1);
        return SourceRow(id, path);
    }
}