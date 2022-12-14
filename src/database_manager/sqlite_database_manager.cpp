#include "sqlite_database_manager.h"
#include <exceptions/database_exception.h>

#include <iostream>
#include <string>
#include <map>

sqlite3 *SQLiteDatabaseManager::connect_to_database(const char *db_dir_name)
{

    sqlite3 *db;
    int result;

    result = sqlite3_open(db_dir_name, &db);

    if (result)
    {
        throw DatabaseException((char *)sqlite3_errmsg(db));
    }

    return db;
}

void SQLiteDatabaseManager::close_database_connection(sqlite3 *db)
{
    sqlite3_close(db);
}

void SQLiteDatabaseManager::execute_statement(sqlite3 *db, std::string sql_statement)
{
    int result;

    result = sqlite3_exec(db, sql_statement.data(), NULL, 0, NULL);

    if (result != SQLITE_OK)
    {
        throw DatabaseException((char *)sqlite3_errmsg(db));
    }
}

void SQLiteDatabaseManager::create_tables(sqlite3 *db)
{
    std::string user_table, character_table, attack_table;
    user_table = "CREATE TABLE IF NOT EXISTS USERS("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                 "IS_ADMIN       INT                   NOT NULL,"
                 "USERNAME       VARCHAR(255)          NOT NULL UNIQUE,"
                 "PASSWORD       VARCHAR(255)          NOT NULL,"
                 "FIRST_NAME     VARCHAR(255)          NOT NULL, "
                 "LAST_NAME      VARCHAR(255)          NOT NULL);";

    character_table = "CREATE TABLE IF NOT EXISTS CHARACTERS("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                      "CLASS          VARCHAR(255)          NOT NULL,"
                      "NAME           VARCHAR(255)          NOT NULL ,"
                      "GENDER         VARCHAR(255)          NOT NULL,"
                      "AGE            INT                   NOT NULL,"
                      "LEVEL          INT                   NOT NULL,"
                      "VIGOR          INT                   NOT NULL,"
                      "ENDURANCE      INT                   NOT NULL,"
                      "STRENGTH       INT                   NOT NULL,"
                      "DEXTERITY      INT                   NOT NULL,"
                      "INTELIGENCE    INT                   NOT NULL,"
                      "FAITH          INT                   NOT NULL,"
                      "USER_ID        INT                   NOT NULL);";

    attack_table = "CREATE TABLE IF NOT EXISTS ATTACKS("
                   "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                   "NAME                    VARCHAR(255) NOT NULL UNIQUE,"
                   "DAMAGE_DEALT            INT          NOT NULL,"
                   "ENDURANCE_CONSUMPTION   INT          NOT NULL,"
                   "MANA_CONSUMPTION        INT          NOT NULL,"
                   "STR_REQ                 INT          NOT NULL,"
                   "DEX_REQ                 INT          NOT NULL,"
                   "INT_REQ                 INT          NOT NULL,"
                   "FAITH_REQ               INT          NOT NULL);";

    this->execute_statement(db, user_table);
    this->execute_statement(db, character_table);
    this->execute_statement(db, attack_table);
}

std::map<int, std::map<std::string, std::string>>
SQLiteDatabaseManager::select(sqlite3 *db, std::string statement)
{
    int result;
    sqlite3_stmt *stmt;
    const unsigned char *col_value;
    const char *col_name;
    std::map<std::string, std::string> row_results;
    std::map<int, std::map<std::string, std::string>> results;

    result = sqlite3_prepare(db, statement.data(), -1, &stmt, NULL);

    if (result != SQLITE_OK)
    {
        sqlite3_finalize(stmt);
        throw DatabaseException((char *)sqlite3_errmsg(db));
    }

    bool done = false;
    int row = 1;
    while (!done)
    {
        switch (sqlite3_step(stmt))
        {
        case SQLITE_ROW:
            row_results.clear();
            for (int i = 0; i < sqlite3_data_count(stmt); i++)
            {
                col_name = sqlite3_column_name(stmt, i);
                col_value = sqlite3_column_text(stmt, i);
                std::string col_name_str = col_name;
                std::string col_value_str = std::string(reinterpret_cast<const char *>(col_value));
                row_results.insert({col_name_str,
                                    col_value_str});
            }
            results.insert({row, row_results});
            row++;
            break;
        case SQLITE_DONE:
            done = true;
            break;
        default:
            sqlite3_finalize(stmt);
            throw DatabaseException("Failed when reading table rows...");
        }
    }

    sqlite3_finalize(stmt);
    return results;
}

void SQLiteDatabaseManager::create_admin_user(sqlite3 *db)
{
    std::string stmt = "INSERT INTO USERS(IS_ADMIN, USERNAME, PASSWORD, FIRST_NAME, LAST_NAME)\n"
                       "VALUES ('1', 'admin', 'admin', 'admin', 'admin');";

    try
    {
        this->execute_statement(db, stmt);
    }
    catch (DatabaseException e)
    {
        // user exits, that's fine, we just continue :)
        // if we have dedicated logging levels, we can log here
    }
}