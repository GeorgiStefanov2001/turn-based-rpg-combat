#include "user_service.h"
#include <database_manager/sqlite_database_manager.h>
#include "exceptions/database_exception.h"

#include <iostream>
#include <string>
#include <list>

UserService::UserService(SQLiteDatabaseManager database_manager, sqlite3 *db)
{
    this->database_manager = database_manager;
    this->db = db;
}

User UserService::create_user(
    std::string username,
    std::string password,
    std::string first_name,
    std::string last_name)
{

    User user(false, username, password, first_name, last_name);

    std::string insert_statement;
    std::string is_user_admin = user.get_is_admin() ? "1" : "0";
    insert_statement = "INSERT INTO USERS (IS_ADMIN, USERNAME, PASSWORD, FIRST_NAME, LAST_NAME)\nVALUES ('" +
                       is_user_admin + "', '" + user.get_username() + "', '" + user.get_password() + "', '" + user.get_first_name() + "', '" + user.get_last_name() + "');";

    try
    {
        this->database_manager.execute_statement(this->db, insert_statement);
    }
    catch (DatabaseException e)
    {
        throw;
    }

    return user;
}