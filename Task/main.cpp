#include "task.h"

using namespace SUBD;

int main(){
    Data_Base db;
    db.select();
    db.printTable("departament");
    db.printTable("employee_1");
    db.sample();
    db.printTable("employee_2");
    return 0;
}
