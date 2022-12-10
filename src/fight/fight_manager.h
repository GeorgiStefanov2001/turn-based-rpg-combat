#ifndef __FIGHT_MANAGER_H_INCLUDED__
#define __FIGHT_MANAGER_H_INCLUDED__

#include <character/character.h>
#include <user/user.h>
#include <services/character_service.h>
#include <services/attack_service.h>
#include <database_manager/sqlite_database_manager.h>

#include <sqlite3.h>

#include <list>

class FightManager
{
    sqlite3 *db;
    CharacterService *service;
    SQLiteDatabaseManager db_manager;
    AttackService *attack_service;

public:
    FightManager(sqlite3 *db, SQLiteDatabaseManager db_manager);

    void fight(User current_user);

    void choose_action(Character &attacker, Character &attacked);
};

#endif