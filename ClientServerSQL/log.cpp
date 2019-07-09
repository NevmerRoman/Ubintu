#include "log.h"

using namespace ClientServerSQL;

Log::Log(const string fname){
    file = fopen(fname.c_str(), "a");
    if(file == NULL){
        throw(Bad_CSSQL_exception("Error calling socket"));
    }
}

Log::~Log(){
    fclose(file);
}

void Log::WriteLog(const char* fpar, ...){
    va_list parlist;
    va_start(parlist, fpar);
    vfprintf(file, fpar, parlist);
    va_end(parlist);
}
