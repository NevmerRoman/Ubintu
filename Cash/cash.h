#ifndef CASH_H
#define CASH_H

#include <iostream>
#include <deque>
//#include <map>
//#include <utility>
//#include <unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::deque;
//using std::map;
//using std::unordered_map;
//using std::make_pair;
//using std::pair;

namespace ClientServerSQL {

struct KeyValue{
    int k;
    string v;
};

class Cash{

public:
    Cash() = default;
    ~Cash() = default;

    void Insert(int, string);
    string Get(int);
    int Find(int);
    void Print();

private:
    deque <KeyValue> storage;
    KeyValue kv;

    Cash(const Cash &other) = delete;
    Cash(Cash &&other) = delete;
    Cash operator = (const Cash &other) = delete;
    Cash operator = (Cash &&other) = delete;
};

}

#endif // CASH_H
