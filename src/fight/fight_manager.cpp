#include "fight_manager.h"
#include <user/user.h>
#include <exceptions/character_exception.h>
#include <services/attack_service.h>
#include <exceptions/attack_exception.h>

#include <typeinfo>

#include <iostream>
#include <string>
#include <list>

#include <sqlite3.h>

FightManager::FightManager(sqlite3 *db, SQLiteDatabaseManager db_manager)
{
    this->db = db;
    this->db_manager = db_manager;
    this->service = new CharacterService(db_manager, this->db);
    this->attack_service = new AttackService(db_manager, this->db);
}

void FightManager::fight(User current_user)
{
    std::string char1_name, char2_name, char1_class, char2_class;
    Character *ch1, *ch2;
    this->game_over = false;

    std::cout << "\nFight\n"
              << std::endl;

    try
    {
        std::cout << "Enter the name of the first character you want to use in battle: ";
        std::cin >> char1_name;
        ch1 = this->service->get_character(char1_name, current_user);

        do
        {
            std::cout << "Enter the name of the second character you want to use in battle (can't be the same): ";
            std::cin >> char2_name;
        } while (char1_name.compare(char2_name) == 0);
        ch2 = this->service->get_character(char2_name, current_user);

        while (!this->game_over)
        {
            choose_action(*ch1, *ch2);

            if (this->game_over)
                break;

            choose_action(*ch2, *ch1);
        }

        if (!ch1->is_alive())
        {
            std::cout << ch2->get_name() << " wins!\n"
                      << std::endl;
        }
        else if (!ch2->is_alive())
        {
            std::cout << ch1->get_name() << " wins!\n"
                      << std::endl;
        }

        std::cout << "\n* - * - *\n"
                  << std::endl;
    }
    catch (CharacterException e)
    {
        throw;
    }
}

void FightManager::choose_action(Character &attacker, Character &attacked)
{
    int choice;
    std::string attack_choice;
    bool valid_attack = true;

    std::cout << "\n>" << attacker.get_name() << ": Vigor: "
              << attacker.get_current_vigor()
              << ", Endurance: " << attacker.get_current_endurance()
              << ", Mana: " << attacker.get_current_mana();
    std::cout << "\n>" << attacked.get_name() << ": Vigor: "
              << attacked.get_current_vigor()
              << ", Endurance: " << attacked.get_current_endurance()
              << ". Mana: " << attacked.get_current_mana() << "\n";

    std::cout
        << "\n> "
        << attacker.get_name() << "'s turn. ";
    std::cout << "Choose an action: \n"
              << std::endl;
    std::cout << "1. Attack" << std::endl;
    std::cout << "2. Special ability" << std::endl;
    std::cout << "3. Pass turn" << std::endl;
    std::cout << "4. Forfeit" << std::endl;
    std::cout << "\nEnter your choice: ";
    std::cin >> choice;
    std::cout << "\n";

    switch (choice)
    {
    case 1:

        std::cout << "Available attacks: ";
        for (const auto attack : attacker.get_available_attacks())
        {
            std::cout << attack << " ";
        }
        std::cout << "\n";
        do
        {
            try
            {
                valid_attack = true;
                std::cout << "Enter a valid attack name ('skip' to skip turn): ";
                std::cin >> attack_choice;

                if (attack_choice.compare("skip") == 0)
                {
                    break;
                }

                std::list<std::string> attacks = attacker.get_available_attacks();
                valid_attack = (std::find(attacks.begin(), attacks.end(), attack_choice) != attacks.end());

                if (valid_attack)
                {
                    Attack attack = attack_service->get_attack(attack_choice);
                    attacker.attack(attacked, attack);
                }
            }
            catch (AttackException e)
            {
                std::cout << e.what() << std::endl;
                valid_attack = false;
            }
        } while (!valid_attack);
        break;
    case 2:
        break;
    case 3:
        std::cout << "> " << attacker.get_name() << " passes their turn..." << std::endl;
        break;
    case 4:
        std::cout << "> " << attacker.get_name() << " forfeits..." << std::endl;
        attacker.forfeit();
        this->game_over = true;
        break;
    default:
        std::cout << "Invalid choice!" << std::endl;
        std::cout << "* - * - *\n"
                  << std::endl;
        break;
    }
}