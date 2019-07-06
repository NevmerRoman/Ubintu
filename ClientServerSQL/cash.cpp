#include "cash.h"

using namespace ClientServerSQL;

void Cash::InsertCash(int key, string value) noexcept(false){
    kv.k = key;
    kv.v = value;
    if(storage.size() < 10){
        storage.push_front(kv);
    }
    else{
        storage.pop_back();
        storage.push_front(kv);
    }
}

string Cash::GetCash(int key){
    for(unsigned int i = 0; i < storage.size(); ++i){
        if(storage[i].k == key)
        return storage[i].v;
    }
    return "Key not found";
}

void Cash::PrintCash(){
    for(unsigned int i = 0; i < storage.size(); ++i){
        cout << storage[i].k << "  " << storage[i].v << endl;
    }
    cout << endl;
}
