#ifndef CLIENT_H
#define CLIENT_H

#include "/home/student/Project/ClientServerSQL/createsocket.h"
#include "/home/student/Project/ClientServerSQL/sendrecv.h"
#include "/home/student/Project/ClientServerSQL/cJSON.h"

namespace ClientServerSQL{

    class Client : public CreateSocket, public SendRecv{
    public:
        Client() noexcept(false);
        ~Client() noexcept;
        void Get(int, int);
        void Set(int, int, string);
    private:
        Client(const Client &other) = delete;
        Client(Client &&other) = delete;
        Client operator = (const Client &other) = delete;
        Client operator = (Client &&other) = delete;

        void Connect() const;
    };

}

#endif // CLIENT_H
