#ifndef CREATESOCKET_H
#define CREATESOCKET_H

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include "bad_cssql_exception.h"

//#include <stdio.h>
//#include <errno.h>
//#include <string.h>
//#include <stdarg.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

namespace ClientServerSQL{

class CreateSocket{
public:
    inline int getsock(){return sock;}
protected:
    int sock;
    struct sockaddr_in sock_addr;

    CreateSocket():sock(MakeSocket()), sock_addr(SockAddr()) {}
    ~CreateSocket() = default;

    CreateSocket(const CreateSocket &other) = delete;
    CreateSocket(CreateSocket &&other) = delete;
    CreateSocket operator = (const CreateSocket &other) = delete;
    CreateSocket operator = (CreateSocket &&other) = delete;

    int MakeSocket() noexcept(false);
    sockaddr_in SockAddr(const int port = 29033);
    void Close();
};

}

#endif // CREATESOCKET_H
