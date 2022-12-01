#include <character/character.h>
#include <character/melee/knight.h>
#include "character_service.h"
#include <database_manager/sqlite_database_manager.h>
#include <exceptions/database_exception.h>

CharacterService::CharacterService(SQLiteDatabaseManager database_manager, sqlite3 *db)
{
    this->database_manager = database_manager;
    this->db = db;
}

void CharacterService::create_character(std::string character_class,
                                        std::string name,
                                        std::string gender,
                                        int age,
                                        int level,
                                        int vigor,
                                        int endurance,
                                        int strength,
                                        int dexterity,
                                        int inteligence,
                                        int faith)
{
    std::string insert_statement;
    insert_statement = "INSERT INTO CHARACTERS (CLASS, NAME, GENDER, AGE, LEVEL, VIGOR, ENDURANCE, STRENGTH, DEXTERITY, INTELIGENCE, FAITH)\n"
                       "VALUES ('" +
                       character_class + "', '" + name + "', '" + gender + "', '" + std::to_string(age) +
                       "', '" + std::to_string(level) + "', '" + std::to_string(vigor) + "', '" + std::to_string(endurance) + "', '" +
                       std::to_string(strength) + "', '" + std::to_string(dexterity) + "', '" + std::to_string(inteligence) + "', '" +
                       std::to_string(faith) + "');";

    try
    {
        this->database_manager.execute_statement(this->db, insert_statement);
    }
    catch (DatabaseException e)
    {
        throw;
    }
}