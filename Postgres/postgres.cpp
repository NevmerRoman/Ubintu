#include "postgres.h"

using namespace ClientServerSQL;

Postgres::Postgres(){
    con = PQconnectdb("host=localhost port=5432 dbname=student user=student password=1");
    if(PQstatus(con) != CONNECTION_OK){
        throw(Bad_CSSQL_exception("Cannot open database"));
    }
}

Postgres::~Postgres(){
    PQfinish(con);
    PQclear(result);
}

int Postgres::InsertInDb(int key, char* value){
    stringstream ss;
    string str;

    PQexec(con, "BEGIN TRANSACTION;");
    if(FindInDb(key)){
        ss << "UPDATE key_value SET value = '" << value << "' WHERE key = '" << key << "';";
        str = ss.str();
        result = PQexec(con, str.c_str());
        cout << 1 << endl;
        if(PQresultStatus(result) != PGRES_COMMAND_OK){
            throw(Bad_CSSQL_exception("Cannot update in to database"));
            return 0;
        }
    }
    else {
        ss << "INSERT INTO key_value (key, value) VALUES ('" << key << "', '" << value << "');";
        str = ss.str();
        result = PQexec(con, str.c_str());
        cout << 1 << endl;
        if(PQresultStatus(result) != PGRES_COMMAND_OK){
            throw(Bad_CSSQL_exception("Cannot insert in to database"));
            return 0;
        }
    }
    PQexec(con, "END TRANSACTION;");
    return 1;
}

int Postgres::FindInDb(int key){
    stringstream ss;
    string str;
    ss << "SELECT value FROM key_value WHERE key = '" << key << "';";
    str = ss.str();
    result = PQexec(con, str.c_str());
    if(PQntuples(result) == 0){
        return 0;
    }
    return 1;
}

const char* Postgres::GetFromDb(int key){
    string str;
    if(FindInDb(key)){
        str = PQgetvalue(result, 0, 0);
        return str.c_str();
    }
    return "This key not found";
}
