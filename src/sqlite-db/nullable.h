#pragma once

#include <stdexcept>

namespace yw {
	namespace sqlite {

		template<typename VAL_TYPE, typename PTR_TYPE = void*>
		class nullable {

		public:

			const bool hasValue;
			const VAL_TYPE value;

			nullable() : hasValue(false), value() {}
			
			nullable(const VAL_TYPE& value) : hasValue(true), value(value) {}
			
			nullable(PTR_TYPE value_ptr) : nullable(
				value_ptr == nullptr ? nullable{} : nullable{ VAL_TYPE(value_ptr) }) {}
			
			bool isNull() const { return !hasValue; }
			
			VAL_TYPE getValue() const {
				if (!hasValue) { throw std::runtime_error("No value assigned"); }
				return value;
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