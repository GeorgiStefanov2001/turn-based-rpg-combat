#ifndef __CHARACTER_SERVICE_H_INCLUDED__
#define __CHARACTER_SERVICE_H_INCLUDED__

#include <user/user.h>
#include <character/character.h>
#include <database_manager/sqlite_database_manager.h>

#include <sqlite3.h>

#include <string>
#include <list>
#include <map>

class CharacterService
{
    SQLiteDatabaseManager database_manager;
    sqlite3 *db;

public:
    CharacterService(SQLiteDatabaseManager database_manager, sqlite3 *db);

    std::string get_character_class(std::string name, User owner);

    // TODO: Add get_character that returns map ?

    void create_character(std::string character_class,
                          std::string name,
                          std::string gender,
                          int age,
                          int level,
                          int vigor,
                          int endurance,
                          int strength,
                          int dexterity,
                          int inteligence,
                          int faith);

    void delete_character(Character character);

    void update_character(Character character);
};

#endif