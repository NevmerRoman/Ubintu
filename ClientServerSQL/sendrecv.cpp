#include "sendrecv.h"

using namespace ClientServerSQL;

void SendRecv::Send(int sock, const unsigned int len, const char* request) noexcept(false){
    if( send( sock, request, len, 0 ) < 0 ){
        throw(Bad_CSSQL_exception("Error calling send"));
        return;
    }
}

int SendRecv::findErrRecv(int result) const{
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

string SendRecv::Recv(int sock){
    int result;
    string str;
    char* Buf = new char[100];

    result = recv(sock, Buf, 100, 0);
    if (findErrRecv(result)) return "";

    str = Buf;
    delete Buf;
    return str;
}
