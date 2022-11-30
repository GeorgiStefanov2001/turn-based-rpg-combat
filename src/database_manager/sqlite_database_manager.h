#ifndef __SQLITE_DATABASE_MANAGER_H_INCLUDED__
#define __SQLITE_DATABASE_MANAGER_H_INCLUDED__

#include <sqlite3.h>
#include <string>
#include <map>

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

    /**
     * Execute a statement againts the database.
     */
    void execute_statement(sqlite3 *db, std::string sql_statement);

    /**
     * Create the neccessary tables if they don't exist.
     */
    void create_tables(sqlite3 *db);

    std::map<std::string, std::string> select(sqlite3 *db, std::string statement);
};

#endif