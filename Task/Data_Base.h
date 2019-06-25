#ifndef DATA_BASE_H
#define DATA_BASE_H

#include <iostream>
#include <QCoreApplication>
#include <QtSql>
#include <QTextStream>
#include <QString>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

namespace WorkWithSUBD {
    struct dBase{
        int id;
        QString city;
        QString name;
    };

    struct eBase{
        int id;
        int dep_id;
        int ch_id;
        QString name;
        int salary;
    };

    class Data_Base{
        vector <dBase> dep;
        vector <eBase> emp1;
        vector <eBase> emp2;
        QSqlDatabase con;
    public:
        Data_Base();
        Data_Base(const Data_Base& other) = delete;
        Data_Base(Data_Base&& other) = delete;
        Data_Base operator= (const Data_Base& other) = delete;
        Data_Base operator= (Data_Base&& other) = delete;
        ~Data_Base();

        void select();
        void printTable(string table);
        void sample();
    };
}

#endif // DATA_BASE_H
