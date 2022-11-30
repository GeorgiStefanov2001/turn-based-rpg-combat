#include "logged_in_menu.h"
#include <users/user.h>
#include <database_manager/sqlite_database_manager.h>
#include <controllers/user_controller.h>
#include <exceptions/database_exception.h>
#include <exceptions/user_exception.h>
#include <exceptions/program_exit_exception.h>

#include <sqlite3.h>

#include <iostream>

void LoggedInMenu::display(bool &logged_in, User &user, SQLiteDatabaseManager db_manager, sqlite3 *db)
{
    int choice = 0;
    UserController user_controller(db, db_manager);

    std::cout
        << "\nWelcome, " << user.get_first_name() << "!\n"
        << std::endl;

    while (logged_in)
    {
        std::cout << "1. new choice" << std::endl;
        std::cout << "2. new choice" << std::endl;
        std::cout << "3. Logout" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
                user = user_controller.login_user();
                logged_in = true;
                break;
            case 2:
                user = user_controller.register_user();
                break;
            case 3:
                logged_in = false;
                break;
            case 4:
                throw ProgramExitException("Exiting...");
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
            }
        }
        catch (DatabaseException e)
        {
            throw;
        }
        catch (UserException e)
        {
            std::cout << e.what() << "\n"
                      << std::endl;
        }
    }
}