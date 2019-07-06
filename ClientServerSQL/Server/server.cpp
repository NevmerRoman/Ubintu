#include "server.h"

using namespace ClientServerSQL;

Server::Server() noexcept(false){
    Bind();
    Listen();
    Accept();
    cout << "Server run" << endl;
}

Server::~Server() noexcept{
    Close();
}

void Server::Bind() const{
    if( bind(sock, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0 ){
        throw("Error calling bind");
    }
}

void Server::Listen() const{
    if( listen(sock, 1) ){
        throw("Error calling listen");
    }
}

void Server::Accept(){
    servsock = accept(sock, NULL, NULL);
    if( servsock < 0 ){
        throw("Error calling accept");
    }
}

void Server::Ans(int soc){
    string str = Recv(soc);
    cJSON* jobj = cJSON_Parse(str.c_str());
    string strAction = cJSON_GetObjectItem(jobj, "Action")->valuestring;

    int key;
    string value;

    if(strAction == "get"){
        key = cJSON_GetObjectItem(jobj, "Key")->valueint;
        value = Get(key);

        jobj = cJSON_CreateObject();
        cJSON_AddStringToObject(jobj, "Answer", value.c_str());
        str = cJSON_Print(jobj);
        Send(soc, str.size(), str.c_str());
    }
    else if(strAction == "set"){
        key = cJSON_GetObjectItem(jobj, "Key")->valueint;
        value = cJSON_GetObjectItem(jobj, "Value")->valuestring;

        jobj = cJSON_CreateObject();
        if(Set(key, value)){
            cJSON_AddStringToObject(jobj, "Answer", "Insertion successful");
        }
        else {
            cJSON_AddStringToObject(jobj, "Answer", "Insertion failed");
        }
        str = cJSON_Print(jobj);
        Send(soc, str.size(), str.c_str());
    }
}
