#ifndef POSTGRES_H
#define POSTGRES_H

#include <iostream>
#include <sstream>
#include "/usr/include/postgresql/libpq-fe.h"
#include "/home/student/Project/ClientServerSQL/bad_cssql_exception.h"
#include "workwithstorage.h"

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

namespace ClientServerSQL{

class Postgres : public WorkWithStorage{
public:
    Postgres() noexcept(false);
    ~Postgres();

    Postgres(const Postgres &other) = delete;
    Postgres(Postgres &&other) = delete;
    Postgres operator = (const Postgres &other) = delete;
    Postgres operator = (Postgres &&other) = delete;

    bool Set(int, string) noexcept(false);
    string Get(int);

private:
    PGconn *con;
    PGresult *result;

    int FindInDb(int);
};

}

#endif // POSTGRES_H
