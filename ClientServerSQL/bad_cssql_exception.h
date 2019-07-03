#ifndef BAD_CSSQL_EXCEPTION_H
#define BAD_CSSQL_EXCEPTION_H

#include <iostream>

using std::string;

namespace ClientServerSQL{

class Bad_CSSQL_exception : public std::exception{
    const string error;
public:
    Bad_CSSQL_exception(const string);
    Bad_CSSQL_exception(Bad_CSSQL_exception &&other);
    inline const string what(){ return error; }
};

}
#endif // BAD_CSSQL_EXCEPTION_H
