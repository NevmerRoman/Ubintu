#include "server.h"

using namespace ClientServerSQL;

int main(){
    try {
        // СОЗДАНИЕ СЕРВЕРА
        // по умолчанию port = 29033
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
