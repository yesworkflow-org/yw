#pragma once

#include <string>

namespace yw {
	namespace sqlite {

		template<typename VAL_TYPE, typename PTR_TYPE>
		class nullable {
		
			bool isNull;
			VAL_TYPE assignedValue;
		
		public:
		
			nullable() : isNull(true), assignedValue("") {}
			
			nullable(const VAL_TYPE& value) : isNull(false), assignedValue(value) {}
			
			nullable(PTR_TYPE value_ptr) : nullable(
				value_ptr == nullptr ? nullable{} : nullable{ VAL_TYPE(value_ptr) }) {}
			
			bool null() const { return isNull; }
			
			VAL_TYPE value() const {
				if (isNull) { throw std::runtime_error("No value assigned"); }
				return assignedValue;
			}
		};

		using nullable_string = nullable<std::string, const char*>;
	}
}