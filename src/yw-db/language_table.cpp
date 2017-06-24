#include "yesworkflow_db.h"

using std::string;

namespace yw_db {
    
    long YesWorkflowDB::insertLanguage(const string& name) {
        string sql = "INSERT INTO language(name) VALUES (?);";
        SQLiteStatement statement(db, sql);
        statement.bindText(1, name);
        statement.step();
        return statement.getGeneratedId();
    }

    LanguageRow YesWorkflowDB::selectLanguageById(long requested_id) {
        string sql = "SELECT id, name FROM language WHERE id = ?";
        SQLiteStatement statement(db, sql);
        statement.bindInt64(1, requested_id);
        if (statement.step() != SQLITE_ROW) throw std::runtime_error("No row with that id");
        auto id = statement.getInt64Field(0);
        auto name = statement.getTextField(1);
        return LanguageRow(id, name);
    }

}