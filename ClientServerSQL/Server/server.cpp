#include "server.h"

using namespace ClientServerSQL;

Server::Server() noexcept(false){
        Bind();

        // ЗАПУСКАЕМ ПРОСЛУШИВАНИЕ ВХОДЯЩИХ ПОКЛЮЧЕНИЙ
        Listen();

        // ПОЛУЧАЕМ ВХОДЯЩИЕ ПОДКЛЮЧЕНИЯ
        Accept();
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
    s1 = accept(sock, NULL, NULL);
    if( s1 < 0 ){
        throw("Error calling accept");
    }
}
