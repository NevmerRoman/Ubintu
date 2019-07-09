#include "client.h"

using namespace ClientServerSQL;

Client::~Client() noexcept{
    logfile->WriteLog("Disconnect \t|\t %s\n\n", ctime(&logtime));
    Close();
}

void Client::Connect() const noexcept(false){
    if(connect(sock, (struct sockaddr *)&sock_addr, sizeof(sock_addr))){
        logfile->WriteLog("Error calling connect | %s", ctime(&logtime));
        throw(Bad_CSSQL_exception("Error calling connect"));
    }
    logfile->WriteLog("Connect \t|\t %s", ctime(&logtime));
}

void Client::Get(int soc, int key){
    cJSON* jobj = cJSON_CreateObject();
    string strJ;
    string ans;

    cJSON_AddStringToObject(jobj, "Action", "get");
    cJSON_AddNumberToObject(jobj, "Key", key);
    strJ = cJSON_Print(jobj);

    logfile->WriteLog("Get key: %d \t|\t %s", key, ctime(&logtime));

    Send(soc, strJ.size(), strJ.c_str());
    ans = Recv(soc);
    cout << endl << ans << "\n\n";

    logfile->WriteLog("%s \t|\t %s", ans.c_str(), ctime(&logtime));

    cJSON_Delete(jobj);
}

void Client::Set(int soc, int key, string val){
    cJSON* jobj = cJSON_CreateObject();
    string strJ;
    string ans;

    cJSON_AddStringToObject(jobj, "Action", "set");
    cJSON_AddNumberToObject(jobj, "Key", key);
    cJSON_AddStringToObject(jobj, "Value", val.c_str());
    strJ = cJSON_Print(jobj);

    logfile->WriteLog("Set key: %d value: %s \t|\t %s", key, val.c_str(), ctime(&logtime));

    Send(soc, strJ.size(), strJ.c_str());
    ans = Recv(soc);
    cout << endl << ans << "\n\n";

    logfile->WriteLog("%s \t|\t %s", ans.c_str(), ctime(&logtime));

    cJSON_Delete(jobj);
}
