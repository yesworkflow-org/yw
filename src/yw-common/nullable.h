#pragma once

#include <sstream>
#include <stdexcept>

namespace yw {

    template<typename T>
    class nullable {

    protected:

        bool isSet;
        T value;

    public:

        nullable() : isSet(false), value() {}
        nullable(const T& value) : isSet(true), value(value) {}
        bool hasValue() const { return isSet; }

        T getValue() const {
            if (!isSet) { throw std::runtime_error("No value assigned"); }
            return value;
        }

        std::string str() const {
            std::stringstream ss;
            if (isSet) ss << value; else ss << "NULL";
            return ss.str();
        }

        nullable<T> operator=(const nullable<T>& rhs) {
            isSet = rhs.isSet;
            value = rhs.value;
            return *this;
        }

        bool operator==(const nullable<T>& rhs) const {
            if (isSet) {
                return rhs.isSet && value == rhs.value;
            }
            else {
                return !rhs.isSet;
            }
        }
        
        bool operator!=(const nullable<T>& rhs) const {
            return !(*this == rhs);
        }
    };

    class nullable_string : public nullable<std::string> {
    public:
        nullable_string() : nullable() {}
        nullable_string(const std::string& value) : nullable(value) {}
        nullable_string(const char * c_ptr) : nullable(c_ptr == nullptr ? nullable{} : nullable{ std::string(c_ptr) }) {}
    };

    using row_id = long;

    class nullable_row_id : public nullable<row_id> {
    public:
        enum class generation { not_requested, requested } request;
        nullable_row_id() : nullable() {}
        nullable_row_id(const long& value) : nullable(value) {}
        nullable_row_id(generation request) : nullable{}, request(request) {}
        nullable_row_id operator=(const nullable_row_id& rhs);
    };

    using nullable_long = nullable<long>;

    static const auto null_id = nullable_row_id{ nullable_row_id::generation::not_requested };
    static const auto auto_id = nullable_row_id{ nullable_row_id::generation::requested };
    static const auto null_long = nullable_long{};
    static const auto null_string = nullable_string{};
}