#pragma once

#ifdef _MSC_VER 
#include "targetver.h"
#endif

#include <iostream>
#include <sstream>

#include "antlr4-runtime.h"
#include "yesworkflow_db.h"
#include "annotation_listener.h"
#include "yw_parser_builder.h"
#include "sqlite_db.h"

#ifdef CPPUTEST
#include "CppUTest/SimpleString.h"
inline SimpleString StringFrom(const yw::db::AnnotationRow& row) { return StringFrom(row.str()); }
#endif

#include "yw_test.h"

#ifdef MSTEST
namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			static std::wstring ToString(const yw::db::AnnotationRow& row) { RETURN_WIDE_STRING(row); }
		}
	}
}
#endif
