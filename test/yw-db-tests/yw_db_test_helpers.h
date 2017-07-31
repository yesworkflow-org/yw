#pragma once

#include "yesworkflow_db.h"

#ifdef CPPUTEST
#include "CppUTest/SimpleString.h"
inline SimpleString StringFrom(const yw::db::AnnotationRow& row) { return StringFrom(row.str()); }
inline SimpleString StringFrom(const yw::db::LineRow& row) { return StringFrom(row.str()); }
inline SimpleString StringFrom(const yw::db::AnnotationRow::Tag& tag) { return yw::db::AnnotationRow::to_string(tag).c_str(); }
#endif

#include "yw_test.h"

#ifdef MSTEST
namespace Microsoft {
    namespace VisualStudio {
        namespace CppUnitTestFramework {
            static std::wstring ToString(const yw::db::AnnotationRow& row) { RETURN_WIDE_STRING(row); }
            static std::wstring ToString(const yw::db::LineRow& row) { RETURN_WIDE_STRING(row); }
            static std::wstring ToString(const yw::db::AnnotationRow::Tag& tag) { RETURN_WIDE_STRING(yw::db::AnnotationRow::to_string(tag).c_str()); }
        }
    }
}

#endif