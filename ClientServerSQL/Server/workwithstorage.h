#ifndef WORKWITHSTORAGE_H
#define WORKWITHSTORAGE_H

#include "/home/student/Project/ClientServerSQL/log.h"

namespace ClientServerSQL {

class WorkWithStorage{

public:
    WorkWithStorage() = default;
    virtual ~WorkWithStorage() = default;

    virtual bool Set(int, string) = 0;
    virtual string Get(int) = 0;
};

}

#endif // WORKWITHSTORAGE_H
