#include <user/user.h>
#include <character/character.h>
#include <character/mage/sorcerer.h>
#include "sorcerer_service.h"
#include <database_manager/sqlite_database_manager.h>
#include <exceptions/database_exception.h>

#include <map>
#include <string>

SorcererService::SorcererService(SQLiteDatabaseManager database_manager, sqlite3 *db)
    : CharacterService(database_manager, db)
{
}

void SorcererService::create(std::string name,
                             std::string gender,
                             int age,
                             User owner)
{
    try
    {
        this->create_character(
            "Sorcerer",
            name,
            gender,
            age,
            Sorcerer::start_attrb.at("level"),
            Sorcerer::start_attrb.at("vigor"),
            Sorcerer::start_attrb.at("endurance"),
            Sorcerer::start_attrb.at("strength"),
            Sorcerer::start_attrb.at("dexterity"),
            Sorcerer::start_attrb.at("inteligence"),
            Sorcerer::start_attrb.at("faith"),
            owner);
    }
    catch (DatabaseException e)
    {
        throw;
    }
}