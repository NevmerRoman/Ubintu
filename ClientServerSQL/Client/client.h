#ifndef CLIENT_H
#define CLIENT_H

#include <algorithm>
#include "/home/student/Project/ClientServerSQL/workwithnetwork.h"
#include "/home/student/Project/ClientServerSQL/cJSON.h"
#include "/home/student/Project/ClientServerSQL/log.h"

namespace ClientServerSQL{

class Client : public WorkWithNetwork{
public:
    Client() = default;
    ~Client() noexcept;

    void Connect() const noexcept(false);
    void Get(int, int);
    void Set(int, int, string);

private:
    Log* logfile = new Log("/home/student/Project/ClientServerSQL/Client/ClientLog.txt");
    time_t logtime = time(NULL);

    Client(const Client &other) = delete;
    Client(Client &&other) = delete;
    Client operator = (const Client &other) = delete;
    Client operator = (Client &&other) = delete;
};

}

#endif // CLIENT_H
