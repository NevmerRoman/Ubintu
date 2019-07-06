#include "workwithsql.h"

using namespace ClientServerSQL;

int main(){
    WorkWithSQL wws;
    string val;

    wws.InsertInDb(40, "Misha");
    val = wws.GetFromDb(40);
    cout << val << endl << endl;

    wws.InsertInDb(40, "Sveta");
    val = wws.GetFromDb(40);
    cout << val << endl << endl;

    cout << "Hello World!" << endl;
    return 0;
}
