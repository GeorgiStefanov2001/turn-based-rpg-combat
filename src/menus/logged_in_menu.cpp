#include "logged_in_menu.h"
#include <user/user.h>
#include <database_manager/sqlite_database_manager.h>
#include <controllers/user_controller.h>
#include <controllers/character_controller.h>
#include <exceptions/database_exception.h>
#include <exceptions/user_exception.h>
#include <exceptions/character_exception.h>
#include <exceptions/program_exit_exception.h>

#include <sqlite3.h>

#include <iostream>

void LoggedInMenu::display(bool &logged_in, User &user, SQLiteDatabaseManager db_manager, sqlite3 *db)
{
    int choice = 0;
    UserController user_controller(db, db_manager);
    CharacterController character_controller(db, db_manager);

    std::cout
        << "\nWelcome, " << user.get_first_name() << "!\n"
        << std::endl;

    while (logged_in)
    {
        std::cout << "1. Fight" << std::endl;
        std::cout << "2. Create character" << std::endl;
        std::cout << "3. List my characters" << std::endl;
        std::cout << "4. Delete character" << std::endl;
        std::cout << "5. Update character" << std::endl;
        std::cout << "6. Respec character" << std::endl;
        std::cout << "7. Logout" << std::endl;
        std::cout << "8. Exit" << std::endl;
        if (user.get_is_admin())
        {
            std::cout << "[9]. List users" << std::endl;
            std::cout << "[10]. Update user" << std::endl;
            std::cout << "[11]. Delete user" << std::endl;
        }
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        std::cout << "\n* - * - *\n"
                  << std::endl;

        try
        {
            switch (choice)
            {
            case 1:
                break;
            case 2:
                character_controller.create_character(user);
                break;
            case 3:
                character_controller.list_character_for_user(user);
                break;
            case 4:
                character_controller.delete_character(user);
                break;
            case 5:
                character_controller.update_character(user);
                break;
            case 6:
                break;
            case 7:
                std::cout << "Logging out ..." << std::endl;
                std::cout << "\n* - * - *\n"
                          << std::endl;
                logged_in = false;
                break;
            case 8:
                throw ProgramExitException("Exiting...");
                break;
            case 9:
                user_controller.list_users();
                break;
            case 10:
                user_controller.update_user();
                break;
            case 11:
                user_controller.delete_user(user);
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                std::cout << "* - * - *\n"
                          << std::endl;
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
            std::cout << "* - * - *\n"
                      << std::endl;
        }
        catch (CharacterException e)
        {
            std::cout << "\n"
                      << e.what() << "\n"
                      << std::endl;
            std::cout << "* - * - *\n"
                      << std::endl;
        }
    }
}