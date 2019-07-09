#ifndef STORAGE_H
#define STORAGE_H

#include "cashe.h"
#include "postgres.h"
#include "workwithstorage.h"

namespace ClientServerSQL {

class Storage : public WorkWithStorage{

public:
    Storage() = default;
    ~Storage();

    bool Set(int, string);
    string Get(int);

private:
    Cashe ca;
    Postgres db;

    Log* logfile = new Log("/home/student/Project/ClientServerSQL/Server/ServerLog.txt");
    time_t logtime = time(NULL);

    Storage(const Storage &other) = delete;
    Storage(Storage &&other) = delete;
    Storage operator = (const Storage &other) = delete;
    Storage operator = (Storage &&other) = delete;
};

}

#endif // STORAGE_H
