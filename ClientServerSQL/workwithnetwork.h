#ifndef WORKWITHNETWORK_H
#define WORKWITHNETWORK_H

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <memory.h>

#include "bad_cssql_exception.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

namespace ClientServerSQL{

class WorkWithNetwork{
public:
    inline int getsock(){return sock;}

protected:
    int sock;
    struct sockaddr_in sock_addr;

    WorkWithNetwork():sock(MakeSocket()), sock_addr(SockAddr()) {}
    ~WorkWithNetwork() = default;

    WorkWithNetwork(const WorkWithNetwork &other) = delete;
    WorkWithNetwork(WorkWithNetwork &&other) = delete;
    WorkWithNetwork operator = (const WorkWithNetwork &other) = delete;
    WorkWithNetwork operator = (WorkWithNetwork &&other) = delete;

    int MakeSocket() noexcept(false);
    sockaddr_in SockAddr(const int port = 29033);
    void Close();

    void Send(int, const unsigned int, const char*) noexcept(false);
    string Recv(int);

private:
    int findErrRecv(int) const noexcept(false);
};

}

#endif // WORKWITHNETWORK_H
