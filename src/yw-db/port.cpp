#include "ywdb.h"
#include "insert_statement.h"
#include "select_statement.h"

using std::string;
using namespace yw::sqlite;

namespace yw {
    namespace db {

        void YesWorkflowDB::createPortTable() {
            SQLiteDB::createTable(db, std::string(R"(

                CREATE TABLE port(
                    id              INTEGER         NOT NULL        PRIMARY KEY,
                    program_block   INTEGER         NOT NULL        REFERENCES program_block(id),
                    annotation      INTEGER         NULL            REFERENCES annotation(id),
                    name            TEXT            NOT NULL
                );

            )"));
        }

        row_id YesWorkflowDB::insert(Port& port) {
            string sql = "INSERT INTO port(id, program_block, annotation, name) VALUES (?,?,?,?);";
            InsertStatement statement(db, sql);
            statement.bindNullableId(1, port.id);
            statement.bindId(2, port.programBlockId);
            statement.bindNullableId(3, port.annotationId);
            statement.bindText(4, port.name);
            statement.execute();
            port.id = nullable_row_id{ statement.getGeneratedId() };
            return port.id.getValue();
        }

        Port YesWorkflowDB::selectPortById(const row_id& requested_id) {
            string sql = "SELECT id, program_block, annotation, name FROM port WHERE id = ?";
            SelectStatement statement(db, sql);
            statement.bindId(1, requested_id);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No port row with that id");
            auto id = statement.getNullableIdField(0);
            auto programBlockId = statement.getIdField(1);
            auto annotationId = statement.getNullableIdField(2);
            auto name = statement.getTextField(3);
            return Port(id, programBlockId, annotationId, name);
        }
    }
}