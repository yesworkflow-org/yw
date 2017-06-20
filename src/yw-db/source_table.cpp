#include "yw_db.h"

using std::string;

namespace yw_db {
    
    sqlite3_int64 YesWorkflowDB::insertSource(const string& path) {
        string sql = "INSERT INTO source(path) VALUES (?);";
        sqlite3_stmt* statement;
        sqlite3_prepare_v2(db, sql.c_str(), -1, &statement, 0);
        sqlite3_bind_text(statement, 1, path.c_str(), -1, 0);
        sqlite3_step(statement);
        return sqlite3_last_insert_rowid(db);
    }

    SourceRow YesWorkflowDB::selectSourceById(long requested_id) {
        string sql = "SELECT id, path FROM source WHERE id = ?";
        sqlite3_stmt* statement;
        sqlite3_prepare_v2(db, sql.c_str(), -1, &statement, 0);
        sqlite3_bind_int64(statement, 1, (sqlite3_int64)requested_id);
        if (sqlite3_step(statement) != SQLITE_ROW) throw std::runtime_error("No row with that id");
        auto id = sqlite3_column_int64(statement, 0);
        auto path = sqlite3_column_text(statement, 1);
        return SourceRow(id, path);
    }
}