#ifndef CASHE_H
#define CASHE_H

#include <iostream>
#include <deque>

using std::cout;
using std::endl;
using std::string;
using std::deque;

namespace ClientServerSQL {

struct KeyValue{
    int k;
    string v;
};

class Cash{

public:
    Cash() = default;
    ~Cash() = default;

    void InsertCashe(int, string);
    string GetCashe(int);
    void PrintCashe();

private:
    deque <KeyValue> storage;
    KeyValue kv;

    Cash(const Cash &other) = delete;
    Cash(Cash &&other) = delete;
    Cash operator = (const Cash &other) = delete;
    Cash operator = (Cash &&other) = delete;
};

}

#endif // CASHE_H
