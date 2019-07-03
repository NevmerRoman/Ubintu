#include "client.h"

using namespace ClientServerSQL;

int main(){
    string request;
    string mes;

    try{
        Client client;

        cout << "Enter send or recv or exit: " << endl;
        cin >> request;
        while (request != "exit"){
            if(request == "send"){
                cout << "Enter message: ";
                cin >> mes;
                client.Send(client.getsock(), 3, "mes");
            }
            if(request == "recv"){
                client.Recv(client.getsock());
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
