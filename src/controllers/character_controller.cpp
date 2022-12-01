#include "character_controller.h"
#include <user/user.h>
#include <character/character.h>
#include <services/character_service.h>
#include <services/knight_service.h>
#include <database_manager/sqlite_database_manager.h>
#include <exceptions/database_exception.h>
#include <exceptions/character_exception.h>

#include <iostream>
#include <string>
#include <list>

CharacterController::CharacterController(sqlite3 *db, SQLiteDatabaseManager db_manager)
{
    this->db = db;
    this->knight_service = new KnightService(db_manager, this->db);
}

void CharacterController::create_character(User current_user)
{
    std::string name, gender;
    int age = -1;

    std::cout << "\nCreate a new character\n"
              << std::endl;

    std::cout << "Enter character name: ";
    std::cin >> name;
    std::cout << "Enter character gender: ";
    std::cin >> gender;

    do
    {
        std::cout
            << "Enter age (>= 0): ";
        std::cin >> age;
    } while (age <= 0);

    bool character_exists = false;
    // // bool character_exists = true;
    // bool character_exists = false;
    // try
    // {
    //     // this->service->get_character(username, user);
    // }
    // catch (CharacterException e)
    // {
    //     // user doesnt't exist, we can continue
    //     character_exists = false;
    // }

    if (!character_exists)
    {
        try
        {
            int choice;
            std::cout << "Select character class: " << std::endl;
            std::cout << "1. Knight" << std::endl;
            std::cout << "2. Wizard" << std::endl;
            std::cout << "3. Paladin" << std::endl;
            std::cout << "\nEnter your choice: ";
            std::cin >> choice;

            switch (choice)
            {
            case 1:
                // Knight
                this->knight_service->create_knight(name, gender, age);
                std::cout << "Knight " << name << " created successfully!\n"
                          << std::endl;
                break;
            case 2:
                // Wizard
                break;
            case 3:
                // Paladin
                break;
            default:
                std::cout << "Invalid character class!" << std::endl;
                break;
            }
        }
        catch (DatabaseException e)
        {
            throw;
        }
        catch (CharacterException e)
        {
            throw;
        }
    }
    else
    {
        throw CharacterException("User with given username already exists!");
    }
}
