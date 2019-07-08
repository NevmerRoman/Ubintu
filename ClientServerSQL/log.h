#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <cstdarg>
#include <fstream>
#include <time.h>

using std::cout;
using std::endl;
using std::string;

namespace ClientServerSQL{

class Log{

public:
    Log(const string);
    ~Log();

    void WriteLog(const char*, ...);

private:
    std::FILE *file;

};

}

#endif // LOG_H
