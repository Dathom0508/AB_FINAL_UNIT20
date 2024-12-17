#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <sqlite3.h>
#include <string>

class Database {
private:
    sqlite3* db;
    std::string dbName;

public:
    Database(const std::string& dbName);
    ~Database();

    bool open();
    void close();
    bool executeQuery(const std::string& query);
    sqlite3_stmt* prepareQuery(const std::string& query);
};

#endif 
