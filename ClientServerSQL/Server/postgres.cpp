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

bool Postgres::Set(int key, string value){
    stringstream ss;
    string str;

    PQexec(con, "BEGIN TRANSACTION;");
    if(FindInDb(key)){
        ss << "UPDATE key_value SET value = '" << value << "' WHERE key = '" << key << "';";
        str = ss.str();
        result = PQexec(con, str.c_str());
        if(PQresultStatus(result) != PGRES_COMMAND_OK){
            throw(Bad_CSSQL_exception("Cannot update in to database"));
            return false;
        }
    }
    else {
        ss << "INSERT INTO key_value (key, value) VALUES ('" << key << "', '" << value << "');";
        str = ss.str();
        result = PQexec(con, str.c_str());
        if(PQresultStatus(result) != PGRES_COMMAND_OK){
            throw(Bad_CSSQL_exception("Cannot insert in to database"));
            return false;
        }
    }
    PQexec(con, "END TRANSACTION;");
    return true;
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

string Postgres::Get(int key){
    string str;
    if(FindInDb(key)){
        str = PQgetvalue(result, 0, 0);
        return str;
    }
    return "Key not found";
}
