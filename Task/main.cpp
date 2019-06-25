#include "Data_Base.h"

using namespace WorkWithSUBD;

int main(){
    try{
        Data_Base db;
        db.select();
        db.printTable("departament");
        db.printTable("employee_1");
        db.sample();
        db.printTable("employee_2");
    }
    catch(bad_Data_Base_exception& error){
        cout << error.what() << endl;
    }
    return 0;
}
