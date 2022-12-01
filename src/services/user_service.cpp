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
#include <cctype>

UserService::UserService(SQLiteDatabaseManager database_manager, sqlite3 *db)
{
    this->database_manager = database_manager;
    this->db = db;
}

User UserService::get_user(std::string username)
{
    std::map<int, std::map<std::string, std::string>> ret;
    std::map<std::string, std::string> user_data;
    std::string select_statement;
    select_statement = "SELECT * FROM USERS WHERE USERNAME='" + username + "';";

    User *user;
    try
    {
        ret = this->database_manager.select(this->db, select_statement);

        if (ret.size() == 0)
        {
            // user doesn't exist
            throw UserException("User doesn't exist!");
        }

        int id;
        bool is_admin;

        /**
         * get the first and only element of the map of maps;
         * this would be our user
         */
        user_data = ret.at(1);

        is_admin = atoi(user_data.at("IS_ADMIN").c_str());
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

std::list<User> UserService::list_users()
{
    std::map<int, std::map<std::string, std::string>> ret;
    std::map<std::string, std::string> user_data;
    std::string select_statement;
    select_statement = "SELECT * FROM USERS;";

    User *user;
    std::list<User> users;

    try
    {
        ret = this->database_manager.select(this->db, select_statement);

        if (ret.size() == 0)
        {
            // we didn't find users
            throw UserException("No users found!");
        }

        for (int i = 1; i <= ret.size(); i++)
        {
            int id;
            bool is_admin;

            /**
             * iterate over all the returned users
             */
            user_data = ret.at(i);

            is_admin = atoi(user_data.at("IS_ADMIN").c_str());
            id = atoi(user_data.at("ID").c_str());
            user = new User(
                id,
                is_admin,
                user_data.at("USERNAME"),
                user_data.at("PASSWORD"),
                user_data.at("FIRST_NAME"),
                user_data.at("LAST_NAME"));

            users.push_back(*user);
        }
    }
    catch (DatabaseException e)
    {
        throw;
    }

    return users;
}

void UserService::create_user(
    std::string username,
    std::string password,
    std::string first_name,
    std::string last_name)
{

    std::string insert_statement;
    insert_statement = "INSERT INTO USERS (IS_ADMIN, USERNAME, PASSWORD, FIRST_NAME, LAST_NAME)\nVALUES ('0', '" +
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