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
					tag					INTEGER			NOT NULL,
					qualifies           INTEGER         NULL            REFERENCES annotation(id),
					line				INTEGER			NOT NULL		REFERENCES line(id),
					rank				INTEGER			NOT NULL,
					start				INTEGER         NOT NULL,
					end					INTEGER         NOT NULL,
					keyword				TEXT			NOT NULL,
					value               TEXT            NULL
				);

			)"));
		}

		AnnotationRow getRowFromAnnotationColumns(SelectStatement& statement) {
			auto id = statement.getNullableIdField(0);
			auto tag = static_cast<AnnotationRow::Tag>(statement.getInt64Field(1));
			auto qualifies = statement.getNullableIdField(2);
			auto lineId = statement.getInt64Field(3);
			auto rankOnLine = statement.getInt64Field(4);
			auto start = statement.getInt64Field(5);
			auto end = statement.getInt64Field(6);
			auto keyword = statement.getTextField(7);
			auto value = statement.getNullableTextField(8);
			return AnnotationRow(id, tag, qualifies, lineId, rankOnLine, start, end, keyword, value);
		}

        long YesWorkflowDB::insert(const AnnotationRow& annotation) {
            string sql = "INSERT INTO annotation(id, tag, qualifies, line, rank, start, end, keyword, value) VALUES (?,?,?,?,?,?,?,?,?);";
            InsertStatement statement(db, sql);
			statement.bindNullableId(1, annotation.id);
			statement.bindInt64(2, static_cast<long>(annotation.tag));
			statement.bindNullableId(3, annotation.qualifiesId);
            statement.bindId(4, annotation.lineId);
			statement.bindInt64(5, annotation.rankOnLine);
			statement.bindInt64(6, annotation.start);
			statement.bindInt64(7, annotation.end);
			statement.bindText(8, annotation.keyword);
			statement.bindNullableText(9, annotation.value);
			statement.execute();
            return statement.getGeneratedId();
        }

        AnnotationRow YesWorkflowDB::selectAnnotationById(long requested_id) {
            string sql = "SELECT id, tag, qualifies, line, rank, start, end, keyword, value FROM annotation WHERE id = ?";
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
				SELECT annotation.id, tag, qualifies, line, rank, start, end, keyword, value FROM annotation
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