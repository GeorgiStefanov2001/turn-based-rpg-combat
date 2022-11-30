#include "user_controller.h"
#include <users/user.h>
#include <services/user_service.h>
#include <database_manager/sqlite_database_manager.h>
#include <exceptions/database_exception.h>
#include <exceptions/user_exception.h>

#include <iostream>
#include <string>
#include <list>

UserController::UserController(sqlite3 *db, SQLiteDatabaseManager db_manager)
{
    this->db = db;
    this->service = new UserService(db_manager, this->db);
}

User UserController::register_user()
{
    std::string username, password, first_name, last_name;

    std::cout << "Register user\n"
              << std::endl;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << "Enter first_name: ";
    std::cin >> first_name;
    std::cout << "Enter last_name: ";
    std::cin >> last_name;

    try
    {
        this->service->create_user(username, password, first_name, last_name);
        User user = this->service->get_user(username);
        std::cout << "User " << username << " registered successfully!";
        return user;
    }
    catch (DatabaseException e)
    {
        throw;
    }
    catch (UserException e)
    {
        throw;
    }
}

User UserController::login_user()
{
    std::cout << "Login\n"
              << std::endl;
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    try
    {
        User user = this->service->get_user(username);

        int counter = 0;
        while (user.get_password().compare(password) != 0)
        {
            std::cout << "Wrong password, try again: ";
            std::cin >> password;
            counter++;

            if (counter >= 3)
            {
                std::cout << "Maximum number of password retries hit! Exiting login screen..." << std::endl;
                break;
            }
        }

        return user;
    }
    catch (DatabaseException e)
    {
        throw;
    }
    catch (UserException e)
    {
        throw;
    }
}