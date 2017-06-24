#include "yesworkflow_db.h"

using std::string;

namespace yw_db {
    
    long YesWorkflowDB::insertSource(long model, long language, long file) {
        string sql = "INSERT INTO source(model, language, file) VALUES (?,?,?);";
        SQLiteStatement statement(db, sql);
        statement.bindInt64(1, model);
        statement.bindInt64(2, language);
        statement.bindInt64(3, file);
        statement.step();
        return statement.getGeneratedId();
    }

    SourceRow YesWorkflowDB::selectSourceById(long requested_id) {
        string sql = "SELECT id, model, language, file FROM source WHERE id = ?";
        SQLiteStatement statement(db, sql);
        statement.bindInt64(1, requested_id);
        if (statement.step() != SQLITE_ROW) throw std::runtime_error("No row with that id");
        auto id = statement.getInt64Field(0);
        auto model = statement.getInt64Field(1);
        auto file = statement.getInt64Field(2);
        auto language = statement.getInt64Field(3);
        return SourceRow(id, model, language, file);
    }
}