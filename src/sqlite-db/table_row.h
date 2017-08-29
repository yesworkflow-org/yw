#pragma once

#include <sstream>
#include <typeinfo>

namespace yw {
    namespace sqlite {

        class TableRow {
        public:
            virtual std::string fieldValues() const { return std::string(""); };
            virtual std::string str() const {
                std::stringstream ss;
                ss << typeid(*this).name() << "{" << fieldValues() << "}";
                return ss.str();
            }
        };

        inline std::wstringstream& operator<<(std::wstringstream& wss, const yw::sqlite::TableRow& row) {
            wss << row.str().c_str();
            return wss;
        }

        inline bool operator==(const yw::sqlite::TableRow& lhs, const yw::sqlite::TableRow& rhs) {
            return lhs.str() == rhs.str();
        }

        inline bool operator!=(const yw::sqlite::TableRow& lhs, const yw::sqlite::TableRow& rhs) {
            return lhs.str() != rhs.str();
        }
    }
}

