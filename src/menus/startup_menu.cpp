#include "startup_menu.h"
#include <users/user.h>
#include <database_manager/sqlite_database_manager.h>
#include <controllers/user_controller.h>
#include <exceptions/database_exception.h>
#include <exceptions/user_exception.h>
#include <exceptions/program_exit_exception.h>

#include <sqlite3.h>

#include <iostream>

void StartupMenu::display(bool &logged_in, User &user, SQLiteDatabaseManager db_manager, sqlite3 *db)
{
    int choice = 0;
    UserController user_controller(db, db_manager);

    std::cout
        << "\nWelcome, guest!\n"
        << std::endl;

    while (choice != 3)
    {
        if (logged_in)
            break;

        std::cout << "1. Login" << std::endl;
        std::cout << "2. Register" << std::endl;
        std::cout << "3. Exit" << std::endl;
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
            std::cout << "\n"
                      << e.what() << "\n"
                      << std::endl;
        }
    }
}