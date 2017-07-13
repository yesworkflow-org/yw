#pragma once

#include "yw_test_msvc.h"

#include <iostream>

namespace yw {
	namespace test {

		class AssertMessage {

			char* c_message;

		public:

			AssertMessage(const wchar_t * w_message) {
				if (w_message == nullptr) w_message = L"";
				size_t newsize = (wcslen(w_message) + 1) * 2;
				c_message = new char[newsize];
				wcstombs_s(nullptr, c_message, newsize, w_message, _TRUNCATE);
			}

			~AssertMessage() { delete[] c_message; }

			const char* c_str() const { return c_message; }
		};
	}
}