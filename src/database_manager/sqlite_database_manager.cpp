#include "sqlite_database_manager.h"
#include <exceptions/database_exception.h>

#include <iostream>

sqlite3 *SQLiteDatabaseManager::connect_to_database(const char *db_dir_name)
{

    sqlite3 *db;
    int result;

    // TODO: Actual logging
    std::cout << "log: Trying to connect to database..." << std::endl;

    result = sqlite3_open(db_dir_name, &db);

    if (result)
    {
        std::cerr << sqlite3_errmsg(db) << std::endl;
        throw DatabaseException();
    }

    std::cout << "log: Successfully connected to database.\n"
              << std::endl;

    return db;
}

void SQLiteDatabaseManager::close_database_connection(sqlite3 *db)
{
    std::cout << "log: Closing database connection..." << std::endl;
    sqlite3_close(db);
}

void SQLiteDatabaseManager::execute_statement(sqlite3 *db, std::string sql_statement)
{
    int result;
    char *err_msg;

    result = sqlite3_exec(db, sql_statement.data(), NULL, 0, &err_msg);

    if (result != SQLITE_OK)
    {
        std::cerr << "Error durring sqlite exec: " << err_msg << std::endl;
        sqlite3_free(err_msg);
        throw DatabaseException();
    }

    std::cout << "log: Successfully executed SQL statement.\n"
              << std::endl;
}

void SQLiteDatabaseManager::create_tables(sqlite3 *db)
{
    std::string user_table;
    user_table = "CREATE TABLE IF NOT EXISTS USERS("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                 "IS_ADMIN       INT                   NOT NULL,"
                 "USERNAME       VARCHAR(255)          NOT NULL,"
                 "PASSWORD       VARCHAR(255)          NOT NULL,"
                 "FIRST_NAME     VARCHAR(255)          NOT NULL, "
                 "LAST_NAME      VARCHAR(255)          NOT NULL);";

    this->execute_statement(db, user_table);
}