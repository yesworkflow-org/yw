#include "yesworkflow_db.h"

using std::string;

namespace yw_db {
    
    long YesWorkflowDB::insertFile(const string& name, long owner) {
        string sql = "INSERT INTO file(name, owner) VALUES (?,?);";
        SQLiteStatement statement(db, sql);
        statement.bindText(1, name);
        statement.bindInt64(2, owner);
        statement.step();
        return statement.getGeneratedId();
    }

    FileRow YesWorkflowDB::selectFileById(long requested_id) {
        string sql = "SELECT id, name, owner FROM file WHERE id = ?";
        SQLiteStatement statement(db, sql);
        statement.bindInt64(1, requested_id);
        if (statement.step() != SQLITE_ROW) throw std::runtime_error("No row with that id");
        auto id = statement.getInt64Field(0);
        auto name = statement.getTextField(1);
        auto owner = statement.getInt64Field(2);
        return FileRow(id, name, owner);
    }
}