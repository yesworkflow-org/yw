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

    string YesWorkflowDB::selectSourceById(long id) {
        string sql = "SELECT path FROM source WHERE id = ?";
        sqlite3_stmt* statement;
        sqlite3_prepare_v2(db, sql.c_str(), -1, &statement, 0);
        sqlite3_bind_int64(statement, 1, (sqlite3_int64)id);
        if (sqlite3_step(statement) != SQLITE_ROW) throw std::runtime_error("No row with that id");
        auto source = sqlite3_column_text(statement, 0);
        return string((const char*)source);
    }
}