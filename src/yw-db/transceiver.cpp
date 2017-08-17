#include "yw_db.h"
#include "insert_statement.h"
#include "select_statement.h"

using std::string;
using namespace yw::sqlite;

namespace yw {
    namespace db {

        void YesWorkflowDB::createTransceiverTable() {
            SQLiteDB::createTable(db, std::string(R"(

                CREATE TABLE transceiver(
                    id              INTEGER         NOT NULL        PRIMARY KEY,
                    port            INTEGER         NOT NULL        REFERENCES port(id),
                    data            INTEGER         NOT NULL        REFERENCES data(id),
                    direction       INTEGER         NOT NULL,
                    min_rate        INTEGER         NULL,
                    max_rate        INTEGER         NULL
                );

            )"));
        }

        row_id YesWorkflowDB::insert(const Transceiver& transceiver) {
            string sql = "INSERT INTO transceiver(id, port, data, direction, min_rate, max_rate) VALUES (?,?,?,?,?,?);";
            InsertStatement statement(db, sql);
            statement.bindNullableId(1, transceiver.id);
            statement.bindId(2, transceiver.portId);
            statement.bindId(3, transceiver.dataId);
            statement.bindInt64(4, static_cast<long>(transceiver.direction));
            statement.bindNullableInt64(5, nullable_long(transceiver.minRate));
            statement.bindNullableInt64(6, nullable_long(transceiver.maxRate));
            statement.execute();
            return statement.getGeneratedId();
        }

        Transceiver YesWorkflowDB::selectTransceiverById(const row_id& requested_id) {
            string sql = "SELECT id, port, data, direction, min_rate, max_rate FROM transceiver WHERE id = ?";
            SelectStatement statement(db, sql);
            statement.bindId(1, requested_id);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No transceiver row with that id");
            auto id = statement.getNullableIdField(0);
            auto portId = statement.getIdField(1);
            auto dataId = statement.getIdField(2);
            auto direction = static_cast<Transceiver::Direction>(statement.getInt64Field(3));
            auto minRate = statement.getNullableInt64Field(4);
            auto maxRate = statement.getNullableInt64Field(5);
            return Transceiver(id, portId, dataId, direction, minRate, maxRate);
        }
    }
}