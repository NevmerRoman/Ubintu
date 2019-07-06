#include "postgres.h"

using namespace ClientServerSQL;

int main(){
    Postgres pos;
    string val;

    pos.InsertInDb(40, "Misha");
    val = pos.GetFromDb(40);
    cout << val << endl << endl;

    pos.InsertInDb(40, "Sveta");
    val = pos.GetFromDb(40);
    cout << val << endl << endl;

    cout << "Hello World!" << endl;
    return 0;
}
