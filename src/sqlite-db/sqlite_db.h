#pragma once

#include "sqlite3.h"
#include "sqlite_log.h"

#include <memory>
#include <string>

namespace yw {
    namespace sqlite {

		static const long NULL_ROW_ID = 0L;

		class NullableString {
			bool isNull;
			std::string assignedValue;
		public:
			NullableString() : isNull(true), assignedValue("") {}
			NullableString(const std::string& value) : isNull(false), assignedValue(value) {}
			NullableString(const char* value) : NullableString(
				value == nullptr ? NullableString{} : NullableString{ std::string(value) }) {}
			bool null() const { return isNull; }
			std::string value() const {
				if (isNull) { throw std::runtime_error("No value assigned");  }
				return assignedValue;
			}
		};

        class SQLiteDB {

        public:

            SQLiteDB();
            ~SQLiteDB();

            void execute(std::string sql);

            std::string getLastErrorMessage();

            static std::string textToString(const unsigned char* text) {
                return std::string((const char*)text);
            }

            sqlite3* getConnection() { return connection; }

			static void createTable(std::shared_ptr<SQLiteDB> connection, const std::string& sql);

        private:

            SQLiteLog log;
            sqlite3* connection;
        };

    }
}

