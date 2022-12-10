#ifndef __KNIGHT_SERVICE_H_INCLUDED__
#define __KNIGHT_SERVICE_H_INCLUDED__

#include "character_service.h"
#include <character/melee/knight.h>
#include <user/user.h>
#include <database_manager/sqlite_database_manager.h>

#include <sqlite3.h>

#include <string>
#include <list>

class KnightService : public CharacterService
{
    SQLiteDatabaseManager database_manager;
    sqlite3 *db;

public:
    KnightService(SQLiteDatabaseManager database_manager, sqlite3 *db);

    void create(std::string name,
                std::string gender,
                int age,
                User owner);
};

#endif