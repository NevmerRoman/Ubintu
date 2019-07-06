#include "server.h"

using namespace ClientServerSQL;

Server::Server() noexcept(false){
        Bind();

        // ЗАПУСКАЕМ ПРОСЛУШИВАНИЕ ВХОДЯЩИХ ПОКЛЮЧЕНИЙ
        Listen();

        // ПОЛУЧАЕМ ВХОДЯЩИЕ ПОДКЛЮЧЕНИЯ
        Accept();

        cout << "Server run" << endl;
}

Server::~Server() noexcept{
    //РАЗРЫВ СОЕДИНЕНИЯ И ЗАКРЫТИЕ СОКЕТА
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
    jobj = cJSON_CreateObject();
    if(strAction == "get"){
        cJSON_AddNumberToObject(jobj, "Key", 90);
        cJSON_AddStringToObject(jobj, "Value", "HAH");
        str = cJSON_Print(jobj);
        Send(soc, str.size(), str.c_str());
    }
    else if(strAction == "set"){
        cJSON_AddNumberToObject(jobj, "Key", 5);
        cJSON_AddStringToObject(jobj, "Value", "Loh");
        str = cJSON_Print(jobj);
        Send(soc, str.size(), str.c_str());
    }
}
