#include "ywdb.h"
#include "insert_statement.h"
#include "select_statement.h"

using namespace yw::sqlite;
using std::string;

namespace yw {
    namespace db {

        void YesWorkflowDB::createFlowTemplateTable() {
            SQLiteDB::createTable(db, std::string(R"(

                CREATE TABLE flow_template(
                    id                  INTEGER         NOT NULL        PRIMARY KEY,
                    flow                INTEGER         NULL            REFERENCES flow(id),
                    scheme              TEXT            NULL,
                    path                TEXT            NOT NULL
                );

            )"));
        }

        row_id YesWorkflowDB::insert(const FlowTemplate& pathTemplate) {
            string sql = "INSERT INTO flow_template(id, flow, scheme, path) VALUES (?,?,?,?);";
            InsertStatement statement(db, sql);
            statement.bindNullableId(1, pathTemplate.id);
            statement.bindId(2, pathTemplate.flow);
            statement.bindNullableText(3, pathTemplate.scheme);
            statement.bindText(4, pathTemplate.path);
            statement.execute();
            return statement.getGeneratedId();
        }

        FlowTemplate YesWorkflowDB::selectFlowTemplateById(const row_id& requested_id) {
            string sql = "SELECT id, flow, scheme, path FROM flow_template WHERE id = ?";
            SelectStatement statement(db, sql);
            statement.bindInt64(1, requested_id);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No flow template with that id");
            auto id = statement.getNullableIdField(0);
            auto flow = statement.getIdField(1);
            auto scheme = statement.getNullableTextField(2);
            auto path = statement.getTextField(3);
            return FlowTemplate{ id, flow, scheme, path };
        }
    }
}