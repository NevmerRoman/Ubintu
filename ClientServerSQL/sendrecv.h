#ifndef SENDRECV_H
#define SENDRECV_H

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <memory.h>

#include "bad_cssql_exception.h"

using std::cout;
using std::endl;

namespace ClientServerSQL{

class SendRecv{
public:
    void Send(int, const unsigned int, const char*) noexcept(false);
    void Recv(int);
//private:
    SendRecv() = default;
    ~SendRecv() = default;

    int findErrRecv(int) const;
};

}
#endif // SENDRECV_H
