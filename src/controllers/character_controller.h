#ifndef __CHARACTER_CONTROLLER_H_INCLUDED__
#define __CHARACTER_CONTROLLER_H_INCLUDED__

#include <character/character.h>
#include <services/knight_service.h>
#include <database_manager/sqlite_database_manager.h>

#include <sqlite3.h>

#include <list>

class CharacterController
{
    sqlite3 *db;
    KnightService *knight_service;

public:
    CharacterController(sqlite3 *db, SQLiteDatabaseManager db_manager);

    // void list_users();

    void create_character(User current_user);

    // User login_user();

    // void delete_user(User logged_user);

    // void update_user();
};

#endif