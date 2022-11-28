#include "sqlite_database_manager.h"
#include <exceptions/database_connection_exception.h>

#include <iostream>

sqlite3 *SQLiteDatabaseManager::connect_to_database(const char *db_dir_name)
{

    sqlite3 *db;
    int rc;

    // TODO: Actual logging
    std::cout << "log: Trying to connect to database..." << std::endl;

    rc = sqlite3_open(db_dir_name, &db);

    if (rc)
    {
        std::cout << sqlite3_errmsg(db) << std::endl;
        throw DatabaseConnectionException();
    }

    std::cout << "log: Successfully connected to database." << std::endl;

    return db;
}

void SQLiteDatabaseManager::close_database_connection(sqlite3 *db)
{
    std::cout << "log: Closing database connection..." << std::endl;
    sqlite3_close(db);
}
