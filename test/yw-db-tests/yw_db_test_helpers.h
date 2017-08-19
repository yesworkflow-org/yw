#pragma once

#include "ywdb.h"

#ifdef CPPUTEST
#include "CppUTest/SimpleString.h"
inline SimpleString StringFrom(const yw::db::Annotation& row) { return StringFrom(row.str()); }
inline SimpleString StringFrom(const yw::db::Extraction& row) { return StringFrom(row.str()); }
inline SimpleString StringFrom(const yw::db::File& row) { return StringFrom(row.str()); }
inline SimpleString StringFrom(const yw::db::Line& row) { return StringFrom(row.str()); }
inline SimpleString StringFrom(const yw::db::Annotation::Tag& tag) { return yw::db::Annotation::to_string(tag).c_str(); }
inline SimpleString StringFrom(const yw::db::Transceiver::Direction& direction) { return yw::db::Transceiver::to_string(direction).c_str(); }
#endif

#include "yw_test.h"

#ifdef MSTEST
namespace Microsoft {
    namespace VisualStudio {
        namespace CppUnitTestFramework {
            static std::wstring ToString(const yw::db::Annotation& row) { RETURN_WIDE_STRING(row); }
            static std::wstring ToString(const yw::db::Extraction& row) { RETURN_WIDE_STRING(row); }
            static std::wstring ToString(const yw::db::File& row) { RETURN_WIDE_STRING(row); }
            static std::wstring ToString(const yw::db::Line& row) { RETURN_WIDE_STRING(row); }
            static std::wstring ToString(const yw::db::ProgramBlock& row) { RETURN_WIDE_STRING(row); }
            static std::wstring ToString(const yw::db::Annotation::Tag& tag) { RETURN_WIDE_STRING(yw::db::Annotation::to_string(tag).c_str()); }
            static std::wstring ToString(const yw::db::Transceiver::Direction& direction) { RETURN_WIDE_STRING(yw::db::Transceiver::to_string(direction).c_str()); }
        }
    }
}

#endif