#include "attack_controller.h"
#include <fight/attack/attack.h>
#include <services/attack_service.h>
#include <database_manager/sqlite_database_manager.h>
#include <exceptions/database_exception.h>
#include <exceptions/attack_exception.h>

#include <iostream>
#include <string>
#include <list>
#include <map>

AttackController::AttackController(sqlite3 *db, SQLiteDatabaseManager db_manager)
{
    this->db = db;
    this->attack_service = new AttackService(db_manager, this->db);
}

void AttackController::create_attack()
{
    std::string name;
    int damage_dealt = -1, end_consumption = -1, mana_consumption = -1, str_req = -1, dex_req = -1, int_req = -1, faith_req = -1;
    std::map<std::string, int> stat_req;

    std::cout << "\nCreate a new attack\n"
              << std::endl;

    std::cout << "Enter attack name: ";
    std::cin >> name;

    bool attack_exists = true;
    try
    {
        this->attack_service->get_attack(name);
    }
    catch (AttackException e)
    {
        // attack doesnt't exist, we can continue
        attack_exists = false;
    }

    if (!attack_exists)
    {

        /**
         * Beauty incoming :)
         * I just want personalized cout messages otherwise could make it into a method
         */
        do
        {
            std::cout << "Enter the damage the attack deals (>0): ";
            std::cin >> damage_dealt;
        } while (damage_dealt <= 0);
        do
        {
            std::cout << "Enter the endurance the attack consumes (>=0): ";
            std::cin >> end_consumption;
        } while (end_consumption < 0);
        do
        {
            std::cout << "Enter the mana the attack consumes (>=0): ";
            std::cin >> mana_consumption;
        } while (mana_consumption < 0);
        do
        {
            std::cout << "Enter the strength requirement of the attack (>=0): ";
            std::cin >> str_req;
        } while (str_req < 0);
        do
        {
            std::cout << "Enter the dexterity requirement of the attack (>=0): ";
            std::cin >> dex_req;
        } while (dex_req < 0);
        do
        {
            std::cout << "Enter the inteligence requirement of the attack (>=0): ";
            std::cin >> int_req;
        } while (int_req < 0);
        do
        {
            std::cout << "Enter the faith requirement of the attack (>=0): ";
            std::cin >> faith_req;
        } while (faith_req < 0);

        stat_req.insert({"strength", str_req});
        stat_req.insert({"dexterity", dex_req});
        stat_req.insert({"inteligence", int_req});
        stat_req.insert({"faith", faith_req});

        try
        {
            this->attack_service->create_attack(name, damage_dealt, end_consumption, mana_consumption, stat_req);
            std::cout << "\nAttack " << name << " created successfully!\n"
                      << std::endl;
            std::cout << "* - * - *\n";
        }
        catch (DatabaseException e)
        {
            throw;
        }
        catch (AttackException e)
        {
            throw;
        }
    }
    else
    {
        throw AttackException("Attack with given name already exists!");
    }
}

// void CharacterController::list_character_for_user(User current_user)
// {
//     std::cout << "\nListing all your characters...\n"
//               << std::endl;

//     try
//     {
//         std::list<Character> characters = this->char_service->list_characters_for_user(current_user);

//         for (const auto &character : characters)
//         {
//             /**
//              * Good thing we overwrote the << operator :)
//              */
//             std::cout << character << std::endl;
//         }
//         std::cout << "\n";
//         std::cout << "* - * - *\n"
//                   << std::endl;
//     }
//     catch (DatabaseException e)
//     {
//         throw;
//     }
//     catch (CharacterException e)
//     {
//         throw;
//     }
// }

// void CharacterController::delete_character(User current_user)
// {
//     std::string name;
//     std::cout << "\nDelete a character\n"
//               << std::endl;
//     std::cout << "Enter name of your character you wish to delete: ";
//     std::cin >> name;

//     try
//     {
//         Character character = this->char_service->get_character(name, current_user);
//         this->char_service->delete_character(character);
//         std::cout << "\nCharacter " << name << " deleted successfully!\n"
//                   << std::endl;
//         std::cout << "* - * - *\n"
//                   << std::endl;
//     }
//     catch (DatabaseException e)
//     {
//         throw;
//     }
//     catch (CharacterException e)
//     {
//         throw;
//     }
// }

// void CharacterController::update_character(User current_user)
// {
//     std::string name, new_name, new_gender;
//     int new_age;
//     std::cout << "\nUpdate character's details\n"
//               << std::endl;
//     std::cout << "Enter name of your character you wish to update: ";
//     std::cin >> name;

//     try
//     {
//         Character character = this->char_service->get_character(name, current_user);

//         std::cout << "Enter new name <enter 'same' to keep current>: ";
//         std::cin >> new_name;
//         std::cout << "Enter new gender <enter 'same' to keep current>: ";
//         std::cin >> new_gender;
//         do
//         {
//             std::cout << "Enter non-negative new age <enter '-1' to keep current>: ";
//             std::cin >> new_age;
//         } while (new_age == 0 || new_age < -1);

//         /**
//          * Extremely beautiful logic follows :)
//          */
//         new_name = (new_name.compare("same") == 0) ? character.get_name() : new_name;
//         new_gender = (new_gender.compare("same") == 0) ? character.get_gender() : new_gender;
//         new_age = (new_age == -1) ? character.get_age() : new_age;

//         character.set_name(new_name);
//         character.set_gender(new_gender);
//         character.set_age(new_age);

//         this->char_service->update_character(character);
//         std::cout << "\nCharacter " << name << " updated successfully!\n"
//                   << std::endl;
//         std::cout << "* - * - *\n"
//                   << std::endl;
//     }
//     catch (DatabaseException e)
//     {
//         throw;
//     }
//     catch (CharacterException e)
//     {
//         throw;
//     }
// }