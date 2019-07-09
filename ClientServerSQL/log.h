#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <cstdarg>
#include <fstream>
#include <time.h>
#include "bad_cssql_exception.h"

using std::cout;
using std::endl;
using std::string;

namespace ClientServerSQL{

class Log{

public:
    Log(const string) noexcept(false);
    ~Log();

    void WriteLog(const char*, ...);

private:
    std::FILE *file;

};

}

#endif // LOG_H
