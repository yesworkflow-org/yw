#include "ywdb.h"
#include "insert_statement.h"
#include "select_statement.h"

using std::string;
using namespace yw::sqlite;

namespace yw {
    namespace db {

        void YesWorkflowDB::createProgramBlockTable() {
            SQLiteDB::createTable(db, std::string(R"(

                CREATE TABLE program_block(
                    id              INTEGER         NOT NULL        PRIMARY KEY,
                    model           INTEGER         NOT NULL        REFERENCES model(id),
                    workflow        INTEGER         NULL            REFERENCES program_block(id),
                    annotation      INTEGER         NULL            REFERENCES annotation(id),
                    name            TEXT            NOT NULL
                );

            )"));
        }

        ProgramBlock getProgramBlockFromAnnotationColumns(SelectStatement& statement) {
            auto id = statement.getNullableIdField(0);
            auto modelId = statement.getIdField(1);
            auto workflowId = statement.getNullableIdField(2);
            auto annotationId = statement.getNullableIdField(3);
            auto name = statement.getTextField(4);
            return ProgramBlock(id, modelId, workflowId, annotationId, name);
        }

        row_id YesWorkflowDB::insert(ProgramBlock& programBlock) {
            programBlock.id = insert(static_cast<const ProgramBlock&>(programBlock));
            return programBlock.id.getValue();
        }

        row_id YesWorkflowDB::insert(const ProgramBlock& programBlock) {
            string sql = "INSERT INTO program_block(id, model, workflow, annotation, name) VALUES (?,?,?,?,?);";
            InsertStatement statement(db, sql);
            statement.bindNullableId(1, programBlock.id);
            statement.bindId(2, programBlock.modelId);
            statement.bindNullableId(3, programBlock.workflowId);
            statement.bindNullableId(4, programBlock.annotationId);
            statement.bindText(5, programBlock.name);
            statement.execute();
            return statement.getGeneratedId();
        }

        ProgramBlock YesWorkflowDB::selectProgramBlockById(const row_id& requested_id) {
            string sql = "SELECT id, model, workflow, annotation, name FROM program_block WHERE id = ?";
            SelectStatement statement(db, sql);
            statement.bindId(1, requested_id);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No program block with that id");
            auto id = statement.getNullableIdField(0);
            return getProgramBlockFromAnnotationColumns(statement);
        }

        ProgramBlock YesWorkflowDB::selectProgramBlockByModelIdAndBlockName(const row_id& modelId, const string& blockName) {
            string sql = "SELECT id, model, workflow, annotation, name FROM program_block WHERE model = ? AND name = ?";
            SelectStatement statement(db, sql);
            statement.bindId(1, modelId);
            statement.bindText(2, blockName);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No program block with that name");
            auto id = statement.getNullableIdField(0);
            return getProgramBlockFromAnnotationColumns(statement);
        }

        std::vector<ProgramBlock> YesWorkflowDB::selectProgramBlocksByWorkflowId(const row_id& workflowId) {
            auto sql = std::string(R"(
                SELECT id, model, workflow, annotation, name 
                FROM program_block 
                WHERE workflow = ?
                ORDER BY name, id
            )");
            SelectStatement statement(db, sql);
            statement.bindNullableId(1, workflowId);
            auto programBlocks = std::vector<ProgramBlock>{};
            while (statement.step() == SQLITE_ROW) {
                programBlocks.push_back(getProgramBlockFromAnnotationColumns(statement));
            }
            return programBlocks;
        }

    }
}