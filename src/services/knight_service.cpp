#include <character/character.h>
#include <character/melee/knight.h>
#include "knight_service.h"
#include <database_manager/sqlite_database_manager.h>
#include <exceptions/database_exception.h>

#include <map>
#include <string>

/**
 * Starting attributes of the Knight class
 */

std::map<std::string, int> start_attrb{
    {"level", 9},
    {"vigor", 12},
    {"endurance", 11},
    {"strength", 13},
    {"dexterity", 12},
    {"inteligence", 9},
    {"faith", 9}};

KnightService::KnightService(SQLiteDatabaseManager database_manager, sqlite3 *db)
    : CharacterService(database_manager, db)
{
}

void KnightService::create_knight(std::string name,
                                  std::string gender,
                                  int age)
{
    try
    {
        this->create_character(
            "Knight",
            name,
            gender,
            age,
            start_attrb.at("level"),
            start_attrb.at("vigor"),
            start_attrb.at("endurance"),
            start_attrb.at("strength"),
            start_attrb.at("dexterity"),
            start_attrb.at("inteligence"),
            start_attrb.at("faith"));
    }
    catch (DatabaseException e)
    {
        throw;
    }
}