#include "server.h"

using namespace ClientServerSQL;

int main(){
    string request;
    string mes;
    try {
        // СОЗДАНИЕ СЕРВЕРА
        // по умолчанию port = 29033
        Server server;

        cout << "Enter send or recv or exit: " << endl;
        cin >> request;
        while (request != "exit"){
            if(request == "send"){
                cout << "Enter message: ";
                cin >> mes;
                server.Send(server.gesockl(), 5, "Hello");
            }
            if(request == "recv"){
                server.Recv(server.gesockl());
            }
            cout << "Enter send or recv or exit: " << endl;
            cin >> request;
        }
    }
    catch(Bad_CSSQL_exception &error){
        cout << error.what() << endl;
    }
    return 0;
}
