#ifndef __CHARACTER_CONTROLLER_H_INCLUDED__
#define __CHARACTER_CONTROLLER_H_INCLUDED__

#include <character/character.h>
#include <services/character_service.h>
#include <services/knight_service.h>
#include <services/sorcerer_service.h>
#include <services/cleric_service.h>
#include <database_manager/sqlite_database_manager.h>

#include <sqlite3.h>

#include <list>

class CharacterController
{
    sqlite3 *db;
    CharacterService *service;
    SQLiteDatabaseManager db_manager;

public:
    CharacterController(sqlite3 *db, SQLiteDatabaseManager db_manager);

    void list_character_for_user(User current_user);

    void create_character(User current_user);

    void delete_character(User current_user);

    void update_character(User current_user);
};

#endif