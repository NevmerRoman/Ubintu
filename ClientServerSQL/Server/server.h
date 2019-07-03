#ifndef SERVER_H
#define SERVER_H

#include "/home/student/Project/ClientServerSQL/createsocket.h"
#include "/home/student/Project/ClientServerSQL/sendrecv.h"
#include "/home/student/Project/ClientServerSQL/cJSON.h"

namespace ClientServerSQL{

    class Server : public CreateSocket, public SendRecv{
    public:
        Server() noexcept(false);
        ~Server() noexcept;
        inline int getsockserv(){return servsock;}
        void Ans(int);
    private:
        int servsock;

        void Bind() const;
        void Accept();
        void Listen() const;

        Server(const Server &other) = delete;
        Server(Server &&other) = delete;
        Server operator = (const Server &other) = delete;
        Server operator = (Server &&other) = delete;
    };

}

#endif // SERVER_H
