#include "fight_manager.h"
#include <user/user.h>
#include <exceptions/character_exception.h>

#include <iostream>
#include <string>
#include <list>

#include <sqlite3.h>

FightManager::FightManager(sqlite3 *db, SQLiteDatabaseManager db_manager)
{
    this->db = db;
    this->db_manager = db_manager;
    this->service = new CharacterService(db_manager, this->db);
}

void FightManager::fight(User current_user)
{
    std::string char1_name, char2_name;

    std::cout << "\nFight\n"
              << std::endl;

    try
    {
        std::cout << "Enter the name of the first character you want to use in battle: ";
        std::cin >> char1_name;
        this->service->get_character(char1_name, current_user);
        std::cout << "Enter the name of the second character you want to use in battle: ";
        std::cin >> char2_name;
        this->service->get_character(char2_name, current_user);
    }
    catch (CharacterException e)
    {
        throw;
    }
}