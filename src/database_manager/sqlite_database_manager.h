#ifndef __SQLITE_DATABASE_MANAGER_H_INCLUDED__
#define __SQLITE_DATABASE_MANAGER_H_INCLUDED__

#include <sqlite3.h>

/**
 * SQLite Database Manager class
 */
class SQLiteDatabaseManager
{
public:
    /**
     * Connect to database. If doesn't exist, create it.
     */
    sqlite3 *connect_to_database(const char *db_dir_name);

    /**
     * Close the database connection.
     */
    void close_database_connection(sqlite3 *db);
};

#endif