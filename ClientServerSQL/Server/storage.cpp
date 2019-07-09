#include "storage.h"

using namespace ClientServerSQL;

bool Storage::Set(int key, string value){
    if(db.Set(key, value)){
        logfile->WriteLog("Request from server InsertFromDb key %d value %s \t|\t %s", key, value.c_str(), ctime(&logtime));
        ca.Set(key, value);
        logfile->WriteLog("Insert in cashe key %d value %s | %s", key, value.c_str(), ctime(&logtime));
        ca.PrintCashe();
        return true;
    }
    return false;
}

string Storage::Get(int key){
    string value = ca.Get(key);
    logfile->WriteLog("Request from server GetCashe key %d \t|\t %s", key, ctime(&logtime));
    if(value != "Key not found"){
        return value;
    }
    else{
        value = db.Get(key);
        logfile->WriteLog("Request from server GetFromDb key %d \t|\t %s", key, ctime(&logtime));
        if(value != "Key not found"){
            ca.Set(key, value);
            logfile->WriteLog("Insert in cashe key %d \t|\t %s", key, ctime(&logtime));
            ca.PrintCashe();
            return value;
        }
    }
    return value;
}
