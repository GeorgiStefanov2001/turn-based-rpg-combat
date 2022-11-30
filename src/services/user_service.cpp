#include <users/user.h>
#include "user_service.h"
#include <database_manager/sqlite_database_manager.h>
#include <exceptions/database_exception.h>
#include <exceptions/user_exception.h>

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <sstream>
#include <stdlib.h>

UserService::UserService(SQLiteDatabaseManager database_manager, sqlite3 *db)
{
    this->database_manager = database_manager;
    this->db = db;
}

User UserService::get_user(std::string username)
{
    std::map<std::string, std::string> user_data;
    std::string select_statement;
    select_statement = "SELECT * FROM USERS WHERE USERNAME='" + username + "';";

    User *user;
    try
    {
        user_data = this->database_manager.select(this->db, select_statement);

        if (user_data.size() == 0)
        {
            // user doesn't exist
            throw UserException("User doesn't exist!");
        }

        int id;
        bool is_admin;

        std::istringstream(user_data.at("IS_ADMIN")) >> is_admin;
        id = atoi(user_data.at("ID").c_str());
        user = new User(
            id,
            is_admin,
            user_data.at("USERNAME"),
            user_data.at("PASSWORD"),
            user_data.at("FIRST_NAME"),
            user_data.at("LAST_NAME"));
    }
    catch (DatabaseException e)
    {
        throw;
    }

    return *user;
}

void UserService::create_user(
    std::string username,
    std::string password,
    std::string first_name,
    std::string last_name)
{

    std::string insert_statement;
    insert_statement = "INSERT INTO USERS (IS_ADMIN, USERNAME, PASSWORD, FIRST_NAME, LAST_NAME)\nVALUES ('FALSE', '" +
                       username + "', '" + password + "', '" + first_name + "', '" + last_name + "');";

    try
    {
        this->database_manager.execute_statement(this->db, insert_statement);
    }
    catch (DatabaseException e)
    {
        throw;
    }
}

void UserService::delete_user(User user)
{
    std::string delete_statement;
    std::string id_to_str = std::to_string(user.get_id());
    delete_statement = "DELETE FROM USERS WHERE ID='" + id_to_str + "';";

    try
    {
        this->database_manager.execute_statement(this->db, delete_statement);
    }
    catch (DatabaseException e)
    {
        throw;
    }
}

void UserService::update_user(User user)
{
    std::string update_statement;
    std::string id_to_str = std::to_string(user.get_id());
    update_statement = "UPDATE USERS SET USERNAME = '" + user.get_username() +
                       "', PASSWORD = '" + user.get_password() + "', FIRST_NAME = '" +
                       user.get_first_name() + "', LAST_NAME = '" + user.get_last_name() + "' WHERE ID='" + id_to_str + "';";

    try
    {
        this->database_manager.execute_statement(this->db, update_statement);
    }
    catch (DatabaseException e)
    {
        throw;
    }
}