#ifndef WORKWITHSQL_H
#define WORKWITHSQL_H

#include <iostream>
#include <sstream>
#include "/usr/include/postgresql/libpq-fe.h"
#include "/home/student/Project/ClientServerSQL/bad_cssql_exception.h"

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

namespace ClientServerSQL{

class WorkWithSQL{
public:
    WorkWithSQL() noexcept(false);
    ~WorkWithSQL();

    WorkWithSQL(const WorkWithSQL &other) = delete;
    WorkWithSQL(WorkWithSQL &&other) = delete;
    WorkWithSQL operator = (const WorkWithSQL &other) = delete;
    WorkWithSQL operator = (WorkWithSQL &&other) = delete;

    int InsertInDb(int, char*);
    const char* GetFromDb(int);

private:
    PGconn *con;
    PGresult *result;

    int FindInDb(int);
};

}

#endif // WORKWITHSQL_H
