#ifndef CASHE_H
#define CASHE_H

#include <iostream>
#include <deque>
#include "workwithstorage.h"

using std::cout;
using std::endl;
using std::string;
using std::deque;

namespace ClientServerSQL {

struct KeyValue{
    int k;
    string v;
};

class Cashe : public WorkWithStorage{

public:
    Cashe() = default;
    ~Cashe() = default;

    bool Set(int, string);
    string Get(int);
    void PrintCashe();

private:
    deque <KeyValue> storage;
    KeyValue kv;

    Cashe(const Cashe &other) = delete;
    Cashe(Cashe &&other) = delete;
    Cashe operator = (const Cashe &other) = delete;
    Cashe operator = (Cashe &&other) = delete;
};

}

#endif // CASHE_H
