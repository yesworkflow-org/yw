#pragma once

#include <stdexcept>

namespace yw {
	namespace sqlite {

		template<typename VAL_TYPE, typename PTR_TYPE = void* >
		class nullable {
		
			bool isSet;
			VAL_TYPE assignedValue;
		
		public:
		
			nullable() : isSet(false) {}
			
			nullable(const VAL_TYPE& value) : isSet(true), assignedValue(value) {}
			
			nullable(PTR_TYPE value_ptr) : nullable(
				value_ptr == nullptr ? nullable{} : nullable{ VAL_TYPE(value_ptr) }) {}
			
			bool hasValue() const { return isSet; }
			bool isNull() const { return !isSet; }
			
			VAL_TYPE value() const {
				if (!isSet) { throw std::runtime_error("No value assigned"); }
				return assignedValue;
			}
		};

		using nullable_long = nullable<long>;
		using nullable_id = nullable<long>;
		using nullable_string = nullable<std::string, const char*>;
		
		static const auto null_id = nullable_long{};
		static const auto null_long = nullable_long{};
		static const auto null_string = nullable_string{};
	}
}