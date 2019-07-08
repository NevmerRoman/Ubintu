#include "workwithstorage.h"

using namespace ClientServerSQL;

bool WorkWithStorage::Set(int key, string value){
    if(InsertInDb(key, value)){
        logfile->WriteLog("Request from server InsertFromDb key %d value %s | %s", key, value.c_str(), ctime(&logtime));
        InsertCashe(key, value);
        logfile->WriteLog("Insert in cashe key %d value %s | %s", key, value.c_str(), ctime(&logtime));
        PrintCashe();
        return true;
    }
    return false;
}

string WorkWithStorage::Get(int key){
    string value = GetCashe(key);
    logfile->WriteLog("Request from server GetCashe key %d | %s", key, ctime(&logtime));
    if(value != "Key not found"){
        return value;
    }
    else{
        value = GetFromDb(key);
        logfile->WriteLog("Request from server GetFromDb key %d | %s", key, ctime(&logtime));
        if(value != "Key not found"){
            InsertCashe(key, value);
            logfile->WriteLog("Insert in cashe key %d | %s", key, ctime(&logtime));
            PrintCashe();
            return value;
        }
    }
    return value;
}
