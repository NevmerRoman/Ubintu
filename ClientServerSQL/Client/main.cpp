#include "client.h"

using namespace ClientServerSQL;

int main(){
    string request;
    string value;
    int key;
    Client client;

    try{
        client.Connect();
        cout << "Enter get or set or exit: ";
        cin >> request;
        while (request != "exit"){
            if(request == "get"){
                cout << "Enter Key: ";
                cin >> key;
                client.Get(client.getsock(), key);
            }
            if(request == "set"){
                cout << "Enter Key: ";
                cin >> key;
                cout << "Enter Value: ";
                cin >> value;
                client.Set(client.getsock(), key, value);
            }
            cout << "Enter get or set or exit: ";
            cin >> request;
        }
    }

    catch(Bad_CSSQL_exception &error){
        cout << error.what() << endl;
    }
    return 0;
}
