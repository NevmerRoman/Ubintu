#include "workwithnetwork.h"

using namespace ClientServerSQL;

int WorkWithNetwork::MakeSocket() noexcept(false){
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0){
        throw(Bad_CSSQL_exception("Error calling socket"));
        return 0;
    }
    return sock;
}

sockaddr_in WorkWithNetwork::SockAddr(const int port){
    sockaddr_in sain;
    sain.sin_family = AF_INET;
    sain.sin_port = htons(port);
    sain.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    return sain;
}

void WorkWithNetwork::Send(int soc, const unsigned int len, const char* request) noexcept(false){
    unsigned char size[4] = {0};
    memcpy(size, &len, 4);

    if( send(soc, size, 4, 0) < 0){
        throw(Bad_CSSQL_exception("Error sending size"));
        return;
    }

    if(send(soc, request, len, 0) < 0){
        throw(Bad_CSSQL_exception("Error while sending message"));
        return;
    }
}

int WorkWithNetwork::findErrRecv(int result) const{
    if (result < 0){
        throw(Bad_CSSQL_exception("Error calling recv"));
        return 1;
    }
    if (result == 0){
        throw(Bad_CSSQL_exception("Disconnected"));
        return 1;
    }
    return 0;
}

string WorkWithNetwork::Recv(int soc){
    int result;
    char size[4];
    unsigned int len;
    string str;

    result = recv (soc, size, 4, 0 );
    if (findErrRecv(result)) return "";
    memcpy(&len, size, 4);

    char* Buf = new char[len];
    memset(Buf, 0, len);

    result = recv(soc, Buf, len, 0);
    if (findErrRecv(result)) return "";

    str = Buf;
    delete[] Buf;
    return str;
}

void WorkWithNetwork::Close(){
    close(sock);
}
