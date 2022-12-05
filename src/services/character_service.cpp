#include <character/character.h>
#include <character/melee/knight.h>
#include <character/mage/sorcerer.h>
#include <character/others/cleric.h>
#include "character_service.h"
#include <database_manager/sqlite_database_manager.h>
#include <exceptions/database_exception.h>
#include <exceptions/character_exception.h>

CharacterService::CharacterService(SQLiteDatabaseManager database_manager, sqlite3 *db)
{
    this->database_manager = database_manager;
    this->db = db;
}

Character *CharacterService::create_character_from_data(std::map<std::string, std::string> character_data)
{
    Character *character;

    int id, age, level, vigor, endurance, strength, dexterity, inteligence, faith;
    std::string name, gender, character_class;
    /**
     * Beautiful code handling incoming...
     */
    id = atoi(character_data.at("ID").c_str());
    name = character_data.at("NAME");
    gender = character_data.at("GENDER");
    character_class = character_data.at("CLASS");
    age = atoi(character_data.at("AGE").c_str());
    level = atoi(character_data.at("LEVEL").c_str());
    vigor = atoi(character_data.at("VIGOR").c_str());
    endurance = atoi(character_data.at("ENDURANCE").c_str());
    strength = atoi(character_data.at("STRENGTH").c_str());
    dexterity = atoi(character_data.at("DEXTERITY").c_str());
    inteligence = atoi(character_data.at("INTELIGENCE").c_str());
    faith = atoi(character_data.at("FAITH").c_str());

    /**
     * We can't create a Character instance since it's the base class and its constructor is protected
     */
    if (character_class.compare("Knight") == 0)
    {
        character = new Knight(id, name, gender, age, level, vigor, endurance, strength, dexterity, inteligence, faith);
    }
    else if (character_class.compare("Sorcerer") == 0)
    {
        character = new Sorcerer(id, name, gender, age, level, vigor, endurance, strength, dexterity, inteligence, faith);
    }
    else if (character_class.compare("Cleric") == 0)
    {
        character = new Cleric(id, name, gender, age, level, vigor, endurance, strength, dexterity, inteligence, faith);
    }

    return character;
}

Character CharacterService::get_character(std::string name, User owner)
{

    std::map<int, std::map<std::string, std::string>> ret;
    std::map<std::string, std::string> character_data;
    std::string select_statement;
    select_statement = "SELECT * FROM CHARACTERS WHERE NAME='" + name + "' AND USER_ID = " + std::to_string(owner.get_id()) + ";";

    Character *character;
    try
    {
        ret = this->database_manager.select(this->db, select_statement);

        if (ret.size() == 0)
        {
            // character doesn't exist
            throw CharacterException("Character doesn't exist!");
        }

        /**
         * get the first and only element of the map of characters;
         * this would be our character
         */
        character_data = ret.at(1);
        character = this->create_character_from_data(character_data);
    }
    catch (DatabaseException e)
    {
        throw;
    }

    return *character;
}

std::list<Character> CharacterService::list_characters_for_user(User owner)
{
    std::map<int, std::map<std::string, std::string>> ret;
    std::map<std::string, std::string> character_data;
    std::string select_statement;
    select_statement = "SELECT * FROM CHARACTERS WHERE USER_ID = " + std::to_string(owner.get_id()) + ";";

    Character *character;
    std::list<Character> characters;

    try
    {
        ret = this->database_manager.select(this->db, select_statement);

        if (ret.size() == 0)
        {
            // we didn't find characaters
            throw CharacterException("No characters found!");
        }

        for (int i = 1; i <= ret.size(); i++)
        {
            /**
             * iterate over all the returned characters
             */

            character_data = ret.at(i);
            character = this->create_character_from_data(character_data);
            characters.push_back(*character);
        }
    }
    catch (DatabaseException e)
    {
        throw;
    }

    return characters;
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
                                        int faith,
                                        User owner)
{
    std::string insert_statement;
    insert_statement = "INSERT INTO CHARACTERS (CLASS, NAME, GENDER, AGE, LEVEL, VIGOR, ENDURANCE, STRENGTH, DEXTERITY, INTELIGENCE, FAITH, USER_ID)\n"
                       "VALUES ('" +
                       character_class + "', '" + name + "', '" + gender + "', '" + std::to_string(age) +
                       "', '" + std::to_string(level) + "', '" + std::to_string(vigor) + "', '" + std::to_string(endurance) + "', '" +
                       std::to_string(strength) + "', '" + std::to_string(dexterity) + "', '" + std::to_string(inteligence) + "', '" +
                       std::to_string(faith) + "', '" + std::to_string(owner.get_id()) + "');";

    try
    {
        this->database_manager.execute_statement(this->db, insert_statement);
    }
    catch (DatabaseException e)
    {
        throw;
    }
}

void CharacterService::delete_character(Character character)
{
    std::string delete_statement;
    delete_statement = "DELETE FROM CHARACTERS WHERE ID='" + std::to_string(character.get_id()) + "';";

    try
    {
        this->database_manager.execute_statement(this->db, delete_statement);
    }
    catch (DatabaseException e)
    {
        throw;
    }
}

void CharacterService::update_character(Character character)
{
    std::string update_statement;
    update_statement = "UPDATE CHARACTERS SET NAME = '" + character.get_name() +
                       "', GENDER = '" + character.get_gender() + "', AGE = '" +
                       std::to_string(character.get_age()) + "' WHERE ID='" + std::to_string(character.get_id()) + "';";

    try
    {
        this->database_manager.execute_statement(this->db, update_statement);
    }
    catch (DatabaseException e)
    {
        throw;
    }
}

void CharacterService::create(std::string name, std::string gender, int age, User owner)
{
    // creating a character
}