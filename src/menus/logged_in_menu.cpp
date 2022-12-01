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
        std::cout << "1. Fight" << std::endl;
        std::cout << "2. List my characters" << std::endl;
        std::cout << "3. Delete character" << std::endl;
        std::cout << "4. Update character" << std::endl;
        std::cout << "5. Respec character" << std::endl;
        std::cout << "6. Logout" << std::endl;
        std::cout << "7. Exit" << std::endl;
        if (user.get_is_admin())
        {
            std::cout << "[8]. List users" << std::endl;
            std::cout << "[9]. Update user" << std::endl;
            std::cout << "[10]. Delete user" << std::endl;
        }
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                logged_in = false;
                break;
            case 7:
                throw ProgramExitException("Exiting...");
                break;
            case 8:
                user_controller.list_users();
                break;
            case 9:
                break;
            case 10:
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