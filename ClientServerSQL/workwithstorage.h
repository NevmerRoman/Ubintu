#ifndef WORKWITHSTORAGE_H
#define WORKWITHSTORAGE_H

#include "/home/student/Project/ClientServerSQL/cashe.h"
#include "/home/student/Project/ClientServerSQL/postgres.h"

namespace ClientServerSQL {

class WorkWithStorage : public Postgres, public Cash{

public:
    WorkWithStorage() = default;
    ~WorkWithStorage() = default;

    bool Set(int, string);
    string Get(int);

private:
    WorkWithStorage(const WorkWithStorage &other) = delete;
    WorkWithStorage(WorkWithStorage &&other) = delete;
    WorkWithStorage operator = (const WorkWithStorage &other) = delete;
    WorkWithStorage operator = (WorkWithStorage &&other) = delete;
};

}

#endif // WORKWITHSTORAGE_H
