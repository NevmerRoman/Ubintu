#include "server.h"

using namespace ClientServerSQL;

Server::Server() noexcept(false){
    Bind();
    Listen();
    Accept();
    cout << "Server run" << endl;
    logfile->WriteLog("Server run | %s", ctime(&logtime));
}

Server::~Server() noexcept{
    logfile->WriteLog("Disconnect \t|\t %s\n\n", ctime(&logtime));
    Close();
    delete wws;
}

void Server::Bind() const{
    if( bind(sock, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0 ){
        logfile->WriteLog("Error calling bind \t|\t %s", ctime(&logtime));
        throw("Error calling bind");
    }
    logfile->WriteLog("Bind \t|\t %s", ctime(&logtime));
}

void Server::Listen() const{
    if( listen(sock, 1) ){
        logfile->WriteLog("Error calling listen \t|\t %s", ctime(&logtime));
        throw("Error calling listen");
    }
    logfile->WriteLog("Listen \t|\t %s", ctime(&logtime));
}

void Server::Accept(){
    servsock = accept(sock, NULL, NULL);
    if( servsock < 0 ){
        logfile->WriteLog("Error calling accept \t|\t %s", ctime(&logtime));
        throw("Error calling accept");
    }
    logfile->WriteLog("Accept \t|\t %s", ctime(&logtime));
}

void Server::Ans(int soc){
    string str = Recv(soc);
    cJSON* jobj = cJSON_Parse(str.c_str());
    string strAction = cJSON_GetObjectItem(jobj, "Action")->valuestring;

    int key;
    string value;

    if(strAction == "get"){
        key = cJSON_GetObjectItem(jobj, "Key")->valueint;
        logfile->WriteLog("Request from client get key %d \t|\t %s", key, ctime(&logtime));
        value = wws->Get(key);

        logfile->WriteLog("Answer to the client: %s \t|\t %s", value.c_str(), ctime(&logtime));
        jobj = cJSON_CreateObject();
        cJSON_AddStringToObject(jobj, "Answer", value.c_str());
        str = cJSON_PrintUnformatted(jobj);
        Send(soc, str.size(), str.c_str());
    }
    else if(strAction == "set"){
        key = cJSON_GetObjectItem(jobj, "Key")->valueint;
        value = cJSON_GetObjectItem(jobj, "Value")->valuestring;
        logfile->WriteLog("Request from client set key %d value %s \t|\t %s", key, value.c_str(), ctime(&logtime));

        jobj = cJSON_CreateObject();
        if(wws->Set(key, value)){
            cJSON_AddStringToObject(jobj, "Answer", "Insertion successful");
            logfile->WriteLog("Answer to the client: Insertion successful \t|\t %s", ctime(&logtime));
        }
        else {
            cJSON_AddStringToObject(jobj, "Answer", "Insertion failed");
            logfile->WriteLog("Answer to the client: Insertion failed \t|\t %s", ctime(&logtime));
        }
        str = cJSON_PrintUnformatted(jobj);
        Send(soc, str.size(), str.c_str());
    }

    cJSON_Delete(jobj);
}
