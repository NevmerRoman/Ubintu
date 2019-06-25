#include "Data_Base.h"

using namespace WorkWithSUBD;

int main(){
    Data_Base db;
    db.select();
    db.printTable("departament");
    db.printTable("employee_1");
    db.sample();
    db.printTable("employee_2");
    return 0;
}
