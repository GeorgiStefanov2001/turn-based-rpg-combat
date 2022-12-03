#include "user_controller.h"
#include <user/user.h>
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

    std::cout << "\nRegister user\n"
              << std::endl;
    std::cout << "Enter username: ";
    std::cin >> username;

    bool user_exists = true;
    try
    {
        this->service->get_user(username);
    }
    catch (UserException e)
    {
        // user doesnt't exist, we can continue
        user_exists = false;
    }

    if (!user_exists)
    {
        std::cout << "Enter password: ";
        std::cin >> password;
        std::cout << "Enter first name: ";
        std::cin >> first_name;
        std::cout << "Enter last name: ";
        std::cin >> last_name;

        try
        {
            this->service->create_user(username, password, first_name, last_name);
            User user = this->service->get_user(username);
            std::cout << "\nUser " << username << " registered successfully!\n"
                      << std::endl;
            std::cout << "* - * - *\n"
                      << std::endl;
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
    else
    {
        throw UserException("User with given username already exists!");
    }
}

User UserController::login_user()
{
    std::cout << "\nLogin\n"
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
                throw UserException("Maximum number of password retries hit!");
            }
        }

        std::cout << "\nSuccessfully logged in!\n"
                  << std::endl;
        std::cout << "* - * - *\n"
                  << std::endl;
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

void UserController::list_users()
{
    std::cout << "\nListing all users...\n"
              << std::endl;

    try
    {
        std::list<User> users = this->service->list_users();

        std::list<User>::iterator it;
        for (it = users.begin(); it != users.end(); it++)
        {
            std::cout << "- " << it->get_username() << ": "
                      << it->get_first_name() << " "
                      << it->get_last_name() << std::endl;
        }
        std::cout << "\n";
        std::cout << "* - * - *\n"
                  << std::endl;
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

void UserController::delete_user(User logged_user)
{
    std::string username;
    std::cout << "\nDelete a user\n"
              << std::endl;
    std::cout << "Enter username of the user you wish to delete: ";
    std::cin >> username;

    while (logged_user.get_username().compare(username) == 0)
    {
        std::cout << "You can't delete yourself! Enter another username: ";
        std::cin >> username;
    }

    try
    {
        User user = this->service->get_user(username);
        this->service->delete_user(user);
        std::cout << "\nUser " << username << " deleted successfully!\n"
                  << std::endl;
        std::cout << "* - * - *\n"
                  << std::endl;
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

void UserController::update_user()
{

    std::string username, new_username, new_password, new_first_name, new_last_name;
    std::cout << "\nUpdate a user\n"
              << std::endl;
    std::cout << "Enter username of the user you wish to update: ";
    std::cin >> username;

    try
    {
        User user = this->service->get_user(username);

        std::cout << "Enter new username <enter 'same' to keep current>: ";
        std::cin >> new_username;
        std::cout << "Enter new password <enter 'same' to keep current>: ";
        std::cin >> new_password;
        std::cout << "Enter new first name <enter 'same' to keep current>: ";
        std::cin >> new_first_name;
        std::cout << "Enter new last name <enter 'same' to keep current>: ";
        std::cin >> new_last_name;

        /**
         * Extremely beautiful logic follows :)
         */
        new_username = (new_username.compare("same") == 0) ? user.get_username() : new_username;
        new_password = (new_password.compare("same") == 0) ? user.get_password() : new_password;
        new_first_name = (new_first_name.compare("same") == 0) ? user.get_first_name() : new_first_name;
        new_last_name = (new_last_name.compare("same") == 0) ? user.get_last_name() : new_last_name;

        user.set_username(new_username);
        user.set_password(new_password);
        user.set_first_name(new_first_name);
        user.set_last_name(new_last_name);

        this->service->update_user(user);
        std::cout << "\nUser " << username << " updated successfully!\n"
                  << std::endl;
        std::cout << "* - * - *\n"
                  << std::endl;
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