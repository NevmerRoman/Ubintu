#include "bad_cssql_exception.h"

using namespace ClientServerSQL;

Bad_CSSQL_exception::Bad_CSSQL_exception(const std::string e) : error(e){}

Bad_CSSQL_exception::Bad_CSSQL_exception(Bad_CSSQL_exception &&other) : error(other.what()){}
