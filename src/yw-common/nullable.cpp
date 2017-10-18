#include "nullable.h"

#include <sstream>
#include <stdexcept>

namespace yw {

    nullable_row_id nullable_row_id::operator=(const nullable_row_id& rhs) {
        isSet = rhs.isSet;
        value = rhs.value;
        request = rhs.request;
        return *this;
    }

}