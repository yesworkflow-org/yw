#include "ywdb.h"
#include "insert_statement.h"
#include "select_statement.h"
#include "vector"

using std::string;
using namespace yw::sqlite;

namespace yw {
    namespace db {

        void YesWorkflowDB::createAnnotationTable() {
            SQLiteDB::createTable(db, std::string(R"(

                CREATE TABLE annotation(
                    id                  INTEGER         NOT NULL        PRIMARY KEY,
                    extraction          INTEGER         NOT NULL        REFERENCES extraction(id),
                    tag                 INTEGER         NOT NULL,
                    qualifies           INTEGER         NULL            REFERENCES annotation(id),
                    line                INTEGER         NOT NULL        REFERENCES line(id),
                    rank                INTEGER         NOT NULL,
                    start               INTEGER         NOT NULL,
                    end                 INTEGER         NOT NULL,
                    keyword             TEXT            NOT NULL,
                    value               TEXT            NULL
                );

            )"));
        }

        Annotation getRowFromAnnotationColumns(SelectStatement& statement) {
            auto id = statement.getNullableIdField(0);
            auto extraction = statement.getIdField(1);
            auto tag = static_cast<Annotation::Tag>(statement.getInt64Field(2));
            auto qualifies = statement.getNullableIdField(3);
            auto lineId = statement.getInt64Field(4);
            auto rankOnLine = statement.getInt64Field(5);
            auto start = statement.getInt64Field(6);
            auto end = statement.getInt64Field(7);
            auto keyword = statement.getTextField(8);
            auto value = statement.getNullableTextField(9);
            return Annotation(id, extraction, tag, qualifies, lineId, rankOnLine, start, end, keyword, value);
        }

        row_id YesWorkflowDB::insert(const Annotation& annotation) {
            string sql = "INSERT INTO annotation(id, extraction, tag, qualifies, line, rank, start, end, keyword, value) VALUES (?,?,?,?,?,?,?,?,?,?);";
            InsertStatement statement(db, sql);
            statement.bindNullableId(1, annotation.id);
            statement.bindNullableId(2, annotation.extractionId);
            statement.bindInt64(3, static_cast<long>(annotation.tag));
            statement.bindNullableId(4, annotation.qualifiesId);
            statement.bindId(5, annotation.lineId);
            statement.bindInt64(6, annotation.rankOnLine);
            statement.bindInt64(7, annotation.start);
            statement.bindInt64(8, annotation.end);
            statement.bindText(9, annotation.keyword);
            statement.bindNullableText(10, annotation.value);
            statement.execute();
            return statement.getGeneratedId();
        }

        Annotation YesWorkflowDB::selectAnnotationById(const row_id& requestedId) {
            string sql = "SELECT id, extraction, tag, qualifies, line, rank, start, end, keyword, value FROM annotation WHERE id = ?";
            SelectStatement statement(db, sql);
            statement.bindId(1, requestedId);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No annotation row with that id");
            return getRowFromAnnotationColumns(statement);
        }

        std::vector<Annotation> YesWorkflowDB::selectTopLevelAnnotations() {
            auto sql = std::string(R"(
                SELECT annotation.id, extraction, tag, qualifies, line, rank, start, end, keyword, value FROM annotation
                JOIN line ON annotation.line=line.id
                WHERE annotation.qualifies IS NULL
                ORDER BY line.number, rank
            )");
            SelectStatement statement(db, sql);
            auto annotations = std::vector<Annotation>{};
            while (statement.step() == SQLITE_ROW) {
                annotations.push_back(getRowFromAnnotationColumns(statement));
            }
            return annotations;
        }

        std::vector<Annotation> YesWorkflowDB::selectAnnotationTree(const nullable_row_id& rootAnnotationId) {

            auto sql = std::string(R"(

                WITH RECURSIVE
                  annotation_tree(id) AS (
                    VALUES(?)
                    UNION
                    SELECT annotation.id FROM annotation, annotation_tree 
                    WHERE annotation.qualifies=annotation_tree.id 
                )
                SELECT annotation.id, extraction, tag, qualifies, line, rank, start, end, keyword, value FROM annotation
                JOIN line ON annotation.line=line.id
                WHERE annotation.id IN annotation_tree;
                ORDER BY line.number, rank

            )");

            SelectStatement statement(db, sql);
            statement.bindNullableId(1, rootAnnotationId);

            auto annotations = std::vector<Annotation>{};
            while (statement.step() == SQLITE_ROW) {
                annotations.push_back(getRowFromAnnotationColumns(statement));
            }

            return annotations;
        }
    }
}