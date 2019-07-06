#ifndef CLIENT_H
#define CLIENT_H

#include "/home/student/Project/ClientServerSQL/workwithnetwork.h"
#include "/home/student/Project/ClientServerSQL/cJSON.h"

namespace ClientServerSQL{

class Client : public WorkWithNetwork{
public:
    Client() = default;
    ~Client() noexcept;

    void Connect() const noexcept(false);
    void Get(int, int);
    void Set(int, int, string);

private:
    Client(const Client &other) = delete;
    Client(Client &&other) = delete;
    Client operator = (const Client &other) = delete;
    Client operator = (Client &&other) = delete;
};

}

#endif // CLIENT_H
