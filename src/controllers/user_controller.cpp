#include "user_controller.h"
#include <users/user.h>
#include <services/user_service.h>
#include <database_manager/sqlite_database_manager.h>
#include <exceptions/database_exception.h>

#include <iostream>
#include <string>
#include <list>

UserController::UserController(sqlite3 *db, SQLiteDatabaseManager db_manager)
{
    this->db = db;
    this->service = new UserService(db_manager, this->db);
}

User UserController::create_user()
{
    std::string username, password, first_name, last_name;
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
        return user;
    }
    catch (DatabaseException e)
    {
        std::cerr << "Error creating user! " << e.what() << std::endl;
        throw;
    }
}