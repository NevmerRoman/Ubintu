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
