#include "createsocket.h"

using namespace ClientServerSQL;

int CreateSocket::MakeSocket(){
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0){
        throw(Bad_CSSQL_exception("Error calling socket"));
        return 0;
    }
    return sock;
}

sockaddr_in CreateSocket::SockAddr(const int port){
    sockaddr_in sain;
    sain.sin_family = AF_INET;
    sain.sin_port = htons(port);
    sain.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    return sain;
}

void CreateSocket::Close(){
    close(sock);
}
