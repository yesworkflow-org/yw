#include "yesworkflow_db.h"
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
					qualifies           INTEGER         NULL            REFERENCES annotation(id),
					line				INTEGER			NOT NULL		REFERENCES line(id),
					rank				INTEGER			NOT NULL,
					start				INTEGER         NOT NULL,
					end					INTEGER         NOT NULL,
					tag					TEXT			NOT NULL,
					value               TEXT            NULL
				);

			)"));
		}

		AnnotationRow getRowFromAnnotationColumns(SelectStatement& statement) {
			auto id = statement.getNullableIdField(0);
			auto qualifies = statement.getNullableIdField(1);
			auto lineId = statement.getInt64Field(2);
			auto rankOnLine = statement.getInt64Field(3);
			auto start = statement.getInt64Field(4);
			auto end = statement.getInt64Field(5);
			auto tag = statement.getTextField(6);
			auto value = statement.getNullableTextField(7);
			return AnnotationRow(id, qualifies, lineId, rankOnLine, start, end, tag, value);
		}

        long YesWorkflowDB::insert(const AnnotationRow& annotation) {
            string sql = "INSERT INTO annotation(id, qualifies, line, rank, start, end, tag, value) VALUES (?,?,?,?,?,?,?,?);";
            InsertStatement statement(db, sql);
			statement.bindNullableId(1, annotation.id);
            statement.bindNullableId(2, annotation.qualifiesId);
            statement.bindId(3, annotation.lineId);
			statement.bindInt64(4, annotation.rankOnLine);
			statement.bindInt64(5, annotation.start);
			statement.bindInt64(6, annotation.end);
			statement.bindText(7, annotation.tag);
			statement.bindNullableText(8, annotation.value);
			statement.execute();
            return statement.getGeneratedId();
        }

        AnnotationRow YesWorkflowDB::selectAnnotationById(long requested_id) {
            string sql = "SELECT id, qualifies, line, rank, start, end, tag, value FROM annotation WHERE id = ?";
            SelectStatement statement(db, sql);
            statement.bindId(1, requested_id);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No row with that id");
			return getRowFromAnnotationColumns(statement);
        }

		std::vector<AnnotationRow> YesWorkflowDB::selectAnnotationTree(row_id rootAnnotationId) {

			auto sql = std::string(R"(

				WITH RECURSIVE
				  annotation_tree(id) AS (
					VALUES(?)
					UNION
					SELECT annotation.id FROM annotation, annotation_tree 
					WHERE annotation.qualifies=annotation_tree.id 
				)
				SELECT annotation.id, qualifies, line, rank, start, end, tag, value FROM annotation
				JOIN line ON annotation.line=line.id
				WHERE annotation.id IN annotation_tree;
			    ORDER BY line.number, rank

			)");

			SelectStatement statement(db, sql);
			statement.bindId(1, rootAnnotationId);

			auto annotations = std::vector<AnnotationRow>{};
			while (statement.step() == SQLITE_ROW) {
				annotations.push_back(getRowFromAnnotationColumns(statement));
			}
			return annotations;
		}

    }
}