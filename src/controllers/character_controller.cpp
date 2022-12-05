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
    this->char_service = new CharacterService(db_manager, this->db);
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

    bool character_exists = true;
    try
    {
        this->char_service->get_character(name, current_user);
    }
    catch (CharacterException e)
    {
        // character doesnt't exist, we can continue
        character_exists = false;
    }

    if (!character_exists)
    {

        std::cout << "Enter character gender: ";
        std::cin >> gender;

        do
        {
            std::cout
                << "Enter age (> 0): ";
            std::cin >> age;
        } while (age <= 0);

        try
        {
            int choice;
            std::cout << "\nSelect character class: " << std::endl;
            std::cout << "1. Knight" << std::endl;
            std::cout << "2. Wizard" << std::endl;
            std::cout << "3. Paladin" << std::endl;
            std::cout << "\nEnter your choice: ";
            std::cin >> choice;

            switch (choice)
            {
            case 1:
                // Knight
                this->knight_service->create_knight(name, gender, age, current_user);
                std::cout << "\nKnight " << name << " created successfully!\n"
                          << std::endl;
                std::cout << "* - * - *\n"
                          << std::endl;
                break;
            case 2:
                // Wizard
                break;
            case 3:
                // Paladin
                break;
            default:
                std::cout << "\nInvalid character class!" << std::endl;
                std::cout << "* - * - *\n"
                          << std::endl;
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
        throw CharacterException("User with given name already exists!");
    }
}

void CharacterController::list_character_for_user(User current_user)
{
    std::cout << "\nListing all your characters...\n"
              << std::endl;

    try
    {
        std::list<Character> characters = this->char_service->list_characters_for_user(current_user);

        for (const auto &character : characters)
        {
            /**
             * Good thing we overwrote the << operator :)
             */
            std::cout << character << "\n"
                      << std::endl;
        }
        std::cout << "\n";
        std::cout << "* - * - *\n"
                  << std::endl;
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

void CharacterController::delete_character(User current_user)
{
    std::string name;
    std::cout << "\nDelete a character\n"
              << std::endl;
    std::cout << "Enter name of your character you wish to delete: ";
    std::cin >> name;

    try
    {
        Character character = this->char_service->get_character(name, current_user);
        this->char_service->delete_character(character);
        std::cout << "\nCharacter " << name << " deleted successfully!\n"
                  << std::endl;
        std::cout << "* - * - *\n"
                  << std::endl;
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

void CharacterController::update_character(User current_user)
{
    std::string name, new_name, new_gender;
    int new_age;
    std::cout << "\nUpdate character's details\n"
              << std::endl;
    std::cout << "Enter name of your character you wish to update: ";
    std::cin >> name;

    try
    {
        Character character = this->char_service->get_character(name, current_user);

        std::cout << "Enter new name <enter 'same' to keep current>: ";
        std::cin >> new_name;
        std::cout << "Enter new gender <enter 'same' to keep current>: ";
        std::cin >> new_gender;
        do
        {
            std::cout << "Enter non-negative new age <enter '-1' to keep current>: ";
            std::cin >> new_age;
        } while (new_age == 0 || new_age < -1);

        /**
         * Extremely beautiful logic follows :)
         */
        new_name = (new_name.compare("same") == 0) ? character.get_name() : new_name;
        new_gender = (new_gender.compare("same") == 0) ? character.get_gender() : new_gender;
        new_age = (new_age == -1) ? character.get_age() : new_age;

        character.set_name(new_name);
        character.set_gender(new_gender);
        character.set_age(new_age);

        this->char_service->update_character(character);
        std::cout << "\nCharacter " << name << " updated successfully!\n"
                  << std::endl;
        std::cout << "* - * - *\n"
                  << std::endl;
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