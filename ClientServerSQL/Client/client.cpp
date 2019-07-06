#include "client.h"

using namespace ClientServerSQL;

Client::~Client() noexcept{
    Close();
}

void Client::Connect() const noexcept(false){
    if(connect(sock, (struct sockaddr *)&sock_addr, sizeof(sock_addr))){
        throw(Bad_CSSQL_exception("Error calling connect"));
    }
}

void Client::Get(int soc, int key){
    cJSON* jobj = cJSON_CreateObject();
    string strJ;

    cJSON_AddStringToObject(jobj, "Action", "get");
    cJSON_AddNumberToObject(jobj, "Key", key);
    strJ = cJSON_Print(jobj);

    Send(soc, strJ.size(), strJ.c_str());
    cout << Recv(soc) << endl;
}

void Client::Set(int soc, int key, string val){
    cJSON* jobj = cJSON_CreateObject();
    string strJ;

    cJSON_AddStringToObject(jobj, "Action", "set");
    cJSON_AddNumberToObject(jobj, "Key", key);
    cJSON_AddStringToObject(jobj, "Value", val.c_str());
    strJ = cJSON_Print(jobj);

    Send(soc, strJ.size(), strJ.c_str());
    cout << Recv(soc) << endl;
}
