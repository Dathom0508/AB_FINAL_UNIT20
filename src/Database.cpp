#include "Database.hpp"
#include <iostream>

Database::Database(const std::string& dbName) : db(nullptr), dbName(dbName) {}

Database::~Database() {
    close();
}

bool Database::open() {
    if (sqlite3_open(dbName.c_str(), &db) == SQLITE_OK) {
        return true;
    } else {
        std::cerr << "Error al abrir la base de datos: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
}

void Database::close() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

bool Database::executeQuery(const std::string& query) {
    char* errMsg = nullptr;
    if (sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg) == SQLITE_OK) {
        return true;
    } else {
        std::cerr << "Error al ejecutar la consulta: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
}

sqlite3_stmt* Database::prepareQuery(const std::string& query) {
    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error al preparar la consulta: " << sqlite3_errmsg(db) << std::endl;
    }
    return stmt;
}
