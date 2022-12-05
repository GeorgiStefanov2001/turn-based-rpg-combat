#ifndef __CLERIC_SERVICE_H_INCLUDED__
#define __CLERIC_SERVICE_H_INCLUDED__

#include "character_service.h"
#include <character/others/cleric.h>
#include <user/user.h>
#include <database_manager/sqlite_database_manager.h>

#include <sqlite3.h>

#include <string>
#include <list>

class ClericService : CharacterService
{
    SQLiteDatabaseManager database_manager;
    sqlite3 *db;

public:
    ClericService(SQLiteDatabaseManager database_manager, sqlite3 *db);

    Cleric get_cleric(std::string name, User user);

    void create_cleric(std::string name,
                       std::string gender,
                       int age,
                       User owner);
};

#endif