#include <user/user.h>
#include <character/character.h>
#include <character/melee/knight.h>
#include "knight_service.h"
#include <database_manager/sqlite_database_manager.h>
#include <exceptions/database_exception.h>

#include <map>
#include <string>

KnightService::KnightService(SQLiteDatabaseManager database_manager, sqlite3 *db)
    : CharacterService(database_manager, db)
{
}

void KnightService::create_knight(std::string name,
                                  std::string gender,
                                  int age,
                                  User owner)
{
    try
    {
        this->create_character(
            "Knight",
            name,
            gender,
            age,
            Knight::start_attrb.at("level"),
            Knight::start_attrb.at("vigor"),
            Knight::start_attrb.at("endurance"),
            Knight::start_attrb.at("strength"),
            Knight::start_attrb.at("dexterity"),
            Knight::start_attrb.at("inteligence"),
            Knight::start_attrb.at("faith"),
            owner);
    }
    catch (DatabaseException e)
    {
        throw;
    }
}