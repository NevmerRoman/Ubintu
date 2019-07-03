#include "client.h"

using namespace ClientServerSQL;

Client::Client() noexcept(false){
    Connect();
}

Client::~Client() noexcept{
    Close();
}

void Client::Connect() const{
    if(connect(sock, (struct sockaddr *)&sock_addr, sizeof(sock_addr))){
        throw(Bad_CSSQL_exception("Error calling connect"));
    }
}

void Client::Get(int soc, int key){
    cJSON* jobj = cJSON_CreateObject();
    string strJ;
    SendRecv sr;

    cJSON_AddNumberToObject(jobj, "Key", key);
    cJSON_AddStringToObject(jobj, "Value", "NULL");
    strJ = cJSON_Print(jobj);

    sr.Send(soc, strJ.size(), strJ.c_str());
    cout << sr.Recv(soc) << endl;
}

void Client::Set(int soc, int key, string val){
    cJSON* jobj = cJSON_CreateObject();
    string strJ;
    SendRecv sr;

    cJSON_AddNumberToObject(jobj, "Key", key);
    cJSON_AddStringToObject(jobj, "Value", val.c_str());
    strJ = cJSON_Print(jobj);

    sr.Send(soc, strJ.size(), strJ.c_str());
    cout << sr.Recv(soc) << endl;
}
