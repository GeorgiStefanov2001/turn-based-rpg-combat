#ifndef __SORCERER_SERVICE_H_INCLUDED__
#define __SORCERER_SERVICE_H_INCLUDED__

#include "character_service.h"
#include <character/mage/sorcerer.h>
#include <user/user.h>
#include <database_manager/sqlite_database_manager.h>

#include <sqlite3.h>

#include <string>
#include <list>

class SorcererService : public CharacterService
{
    SQLiteDatabaseManager database_manager;
    sqlite3 *db;

public:
    SorcererService(SQLiteDatabaseManager database_manager, sqlite3 *db);

    void create(std::string name,
                std::string gender,
                int age,
                User owner);
};

#endif