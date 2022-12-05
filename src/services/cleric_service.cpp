#include <user/user.h>
#include <character/character.h>
#include <character/others/cleric.h>
#include "cleric_service.h"
#include <database_manager/sqlite_database_manager.h>
#include <exceptions/database_exception.h>

#include <map>
#include <string>

ClericService::ClericService(SQLiteDatabaseManager database_manager, sqlite3 *db)
    : CharacterService(database_manager, db)
{
}

// TODO make it create() and make it fully virtual in CharacterService, each child will then implement it here :)
void ClericService::create_cleric(std::string name,
                                  std::string gender,
                                  int age,
                                  User owner)
{
    try
    {
        this->create_character(
            "Cleric",
            name,
            gender,
            age,
            Cleric::start_attrb.at("level"),
            Cleric::start_attrb.at("vigor"),
            Cleric::start_attrb.at("endurance"),
            Cleric::start_attrb.at("strength"),
            Cleric::start_attrb.at("dexterity"),
            Cleric::start_attrb.at("inteligence"),
            Cleric::start_attrb.at("faith"),
            owner);
    }
    catch (DatabaseException e)
    {
        throw;
    }
}