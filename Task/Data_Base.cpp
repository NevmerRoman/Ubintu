#include "Data_Base.h"

using namespace WorkWithSUBD;

Data_Base::Data_Base(){                    //установка соединения с субд
    con = QSqlDatabase::addDatabase("QPSQL");
    con.setDatabaseName("student");
    con.setUserName("student");
    con.setHostName("");
    con.setPassword("1");
    if(!con.open()){
        throw(bad_Data_Base_exception("Cannot open database"));
    }
    else{
        cout << "Connection ok" << endl;
    }
}

Data_Base::~Data_Base(){
    QSqlQuery db;
    dep.clear();
    emp1.clear();
    emp2.clear();
    !db.exec("delete from employee_2");
}

void Data_Base::select(){
    cout << "Enter limit select departament: ";
    int lim;
    cin >> lim;
    cout << endl;
    QSqlQuery db;
    QString str = QStringLiteral("select * from departament limit %1").arg(lim);
    if (!db.exec(str)){
        throw(bad_Data_Base_exception("Unable to execute departament - select"));
    }

    QSqlRecord rec = db.record();
    dBase datad;
    while (db.next()){
        datad.id = db.value(rec.indexOf("id")).toInt();
        datad.city = db.value(rec.indexOf("city")).toString();
        datad.name = db.value(rec.indexOf("name")).toString();
        dep.push_back(datad);
    }

    cout << "Enter limit select employee_1: ";
    cin >> lim;
    cout << endl;
    str = "select * from employee_1 limit %1";
    if (!db.exec(str.arg(lim))){
        throw(bad_Data_Base_exception("Unable to execute employee_1 - select"));
    }

    rec = db.record();
    eBase datae;
    while (db.next()){
        datae.id = db.value(rec.indexOf("id")).toInt();
        datae.dep_id = db.value(rec.indexOf("departament_id")).toInt();
        datae.ch_id = db.value(rec.indexOf("chief_id")).toInt();
        datae.name = db.value(rec.indexOf("name")).toString();
        datae.salary = db.value(rec.indexOf("salary")).toInt();
        emp1.push_back(datae);
    }
}

void Data_Base::printTable(string table){
    if (table == "departament"){
        cout << "Departament table:" << endl;
        for (unsigned int i = 0; i < dep.size(); ++i){
            qDebug() << dep[i].id << "\t"
                     << dep[i].city << "\t"
                     << dep[i].name;
        }
        cout << endl;
    }
    else if (table == "employee_1"){
        cout << "Employee_1 table:" << endl;
        for (unsigned int i = 0; i < emp1.size(); ++i){
            qDebug() << emp1[i].id << "\t"
                     << emp1[i].dep_id << "\t"
                     << emp1[i].ch_id << "\t"
                     << emp1[i].name << "\t"
                     << emp1[i].salary;
        }
        cout << endl;
    }
    else if (table == "employee_2"){
        cout << "Employee_2 table:" << endl;
        for (unsigned int i = 0; i < emp2.size(); ++i){
            qDebug() << emp2[i].id << "\t"
                     << emp2[i].dep_id << "\t"
                     << emp2[i].ch_id << "\t"
                     << emp2[i].name << "\t"
                     << emp2[i].salary;
        }
        cout << endl;
    }
    else{
        throw(bad_Data_Base_exception("This table not found."));
    }
}

void Data_Base::sample(){
    cout << "Enter departament name for sample: ";
    string str;
    cin >> str;
    cout << endl;
    unsigned int lim;
    QString st = QString::fromStdString(str);
    vector <int> depid;
    QSqlQuery db;

    for (unsigned int i = 0; i < dep.size(); ++i){
        if (dep[i].name == st){
            depid.push_back(dep[i].id);
        }
    }

    cout << "ID of selected departaments:" << endl;
    for(unsigned int i = 0; i < depid.size(); ++i){
        cout << depid[i] << " ";
    }
    cout << endl << endl;


    cout << "Enter insert limit: ";
    cin >> lim;
    cout << endl;
    unsigned int i = 0;
    while ((i < emp1.size())&&(lim > 0)){
        for (unsigned int j = 0; j < depid.size(); ++j){
            if (emp1[i].dep_id == depid[j]){
                emp2.push_back(emp1[i]);
                --lim;
            }
        }
        ++i;
    }

    if (!db.exec("select * from employee_2")){
        throw(bad_Data_Base_exception("Unable to execute employee_2 - write to the table"));
    }

    db.exec("begin transaction");
    for (unsigned int i = 0; i < emp2.size(); ++i){
        emp2[i].ch_id = 123;
        QString stIn = "insert into employee_2 "
                            "(id, departament_id, chief_id, name, salary) "
                       "values (%1, %2, %3, '%4', %5);";
        st = stIn.arg(emp2[i].id)
                 .arg(emp2[i].dep_id)
                 .arg(emp2[i].ch_id)
                 .arg(emp2[i].name)
                 .arg(emp2[i].salary);
        if(!db.exec(st)){
            qDebug() << "Unable to make insert operation";
        }
    }
    db.exec("end transaction");
}

bad_Data_Base_exception::bad_Data_Base_exception(const std::string e) : error(e){}
