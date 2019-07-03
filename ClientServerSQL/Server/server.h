#ifndef SERVER_H
#define SERVER_H

#include "/home/student/Project/ClientServerSQL/createsocket.h"
#include "/home/student/Project/ClientServerSQL/sendrecv.h"

namespace ClientServerSQL{

    class Server : public CreateSocket, public SendRecv{
    public:
        Server() noexcept(false);
        ~Server() noexcept;
        inline int gesockl(){return s1;}
    private:
        int s1;

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
