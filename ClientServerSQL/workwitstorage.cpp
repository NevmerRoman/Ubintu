#include "workwithstorage.h"

using namespace ClientServerSQL;

bool WorkWithStorage::Set(int key, string value){
    if(InsertInDb(key, value)){
        InsertCash(key, value);
        PrintCash();
        return true;
    }
    return false;
}

string WorkWithStorage::Get(int key){
    string value = GetCash(key);
    if(value != "Key not found"){
        return value;
    }
    else{
        value = GetFromDb(key);
        if(value != "Key not found"){
            InsertCash(key, value);
            PrintCash();
            return value;
        }
    }

    return value;
}
