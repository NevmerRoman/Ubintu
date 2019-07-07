#include "workwithstorage.h"

using namespace ClientServerSQL;

bool WorkWithStorage::Set(int key, string value){
    if(InsertInDb(key, value)){
        InsertCashe(key, value);
        PrintCashe();
        return true;
    }
    return false;
}

string WorkWithStorage::Get(int key){
    string value = GetCashe(key);
    if(value != "Key not found"){
        return value;
    }
    else{
        value = GetFromDb(key);
        if(value != "Key not found"){
            InsertCashe(key, value);
            PrintCashe();
            return value;
        }
    }

    return value;
}
