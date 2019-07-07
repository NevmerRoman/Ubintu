#include "server.h"

using namespace ClientServerSQL;

int main(){
    try {
        Server server;

        while (1){
            server.Ans(server.getsockserv());
        }
    }
    catch(Bad_CSSQL_exception &error){
        cout << error.what() << endl;
    }
    return 0;
}
