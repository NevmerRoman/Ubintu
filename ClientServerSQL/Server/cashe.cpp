#include "cashe.h"

using namespace ClientServerSQL;

bool Cashe::Set(int key, string value) noexcept(false){
    kv.k = key;
    kv.v = value;

    for(unsigned int i = 0; i < storage.size(); ++i){
        if(storage[i].k == key){
            storage[i].v = value;
            return 1;
        }
    }

    if(storage.size() < 10){
        storage.push_front(kv);
    }
    else{
        storage.pop_back();
        storage.push_front(kv);
    }
    return 1;
}

string Cashe::Get(int key){
    for(unsigned int i = 0; i < storage.size(); ++i){
        if(storage[i].k == key)
        return storage[i].v;
    }
    return "Key not found";
}

void Cashe::PrintCashe(){
    for(unsigned int i = 0; i < storage.size(); ++i){
        cout << storage[i].k << "  " << storage[i].v << endl;
    }
    cout << endl;
}
