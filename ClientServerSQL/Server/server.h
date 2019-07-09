#ifndef SERVER_H
#define SERVER_H

#include "/home/student/Project/ClientServerSQL/workwithnetwork.h"
#include "workwithstorage.h"
#include "storage.h"
#include "/home/student/Project/ClientServerSQL/cJSON.h"
#include "/home/student/Project/ClientServerSQL/log.h"

namespace ClientServerSQL{

class Server : public WorkWithNetwork{
public:
    Server() noexcept(false);
    ~Server();
    inline int getsockserv(){return servsock;}
    void Ans(int);

private:
    int servsock;
    WorkWithStorage* wws = new Storage;
    Log* logfile = new Log("/home/student/Project/ClientServerSQL/Server/ServerLog.txt");
    time_t logtime = time(NULL);

    void Bind() const noexcept(false);
    void Accept() noexcept(false);
    void Listen() const noexcept(false);

    Server(const Server &other) = delete;
    Server(Server &&other) = delete;
    Server operator = (const Server &other) = delete;
    Server operator = (Server &&other) = delete;
};

}

#endif // SERVER_H
