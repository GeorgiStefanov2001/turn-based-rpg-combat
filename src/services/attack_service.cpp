#include <fight/attack/attack.h>
#include "attack_service.h"
#include <database_manager/sqlite_database_manager.h>
#include <exceptions/database_exception.h>
#include <exceptions/attack_exception.h>

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <sstream>
#include <stdlib.h>
#include <cctype>

AttackService::AttackService(SQLiteDatabaseManager database_manager, sqlite3 *db)
{
    this->database_manager = database_manager;
    this->db = db;
}

Attack *AttackService::create_attack_from_data(std::map<std::string, std::string> attack_data)
{
    Attack *attack;

    int id, damage_dealt, endurance_consumption, mana_consumption;
    std::string name;
    std::map<std::string, int> stat_req;

    id = atoi(attack_data.at("ID").c_str());
    name = attack_data.at("NAME");
    damage_dealt = atoi(attack_data.at("DAMAGE_DEALT").c_str());
    endurance_consumption = atoi(attack_data.at("ENDURANCE_CONSUMPTION").c_str());
    mana_consumption = atoi(attack_data.at("MANA_CONSUMPTION").c_str());

    stat_req.insert({"strength", atoi(attack_data.at("STR_REQ").c_str())});
    stat_req.insert({"dexterity", atoi(attack_data.at("DEX_REQ").c_str())});
    stat_req.insert({"inteligence", atoi(attack_data.at("INT_REQ").c_str())});
    stat_req.insert({"faith", atoi(attack_data.at("FAITH_REQ").c_str())});

    attack = new Attack(id, name, damage_dealt, endurance_consumption, mana_consumption, stat_req);

    return attack;
}

Attack AttackService::get_attack(std::string name)
{
    std::map<int, std::map<std::string, std::string>> ret;
    std::map<std::string, std::string> attack_data;
    std::string select_statement;
    select_statement = "SELECT * FROM ATTACKS WHERE NAME='" + name + "';";

    Attack *attack;
    try
    {
        ret = this->database_manager.select(this->db, select_statement);

        if (ret.size() == 0)
        {
            // attack doesn't exist
            throw AttackException("Attack doesn't exist!");
        }

        /**
         * get the first and only element of the map of maps;
         * this would be our attack
         */
        attack_data = ret.at(1);
        attack = this->create_attack_from_data(attack_data);
    }
    catch (DatabaseException e)
    {
        throw;
    }

    return *attack;
}

std::list<Attack> AttackService::list_attacks()
{
    std::map<int, std::map<std::string, std::string>> ret;
    std::map<std::string, std::string> attack_data;
    std::string select_statement;
    select_statement = "SELECT * FROM ATTACKS;";

    Attack *attack;
    std::list<Attack> attacks;

    try
    {
        ret = this->database_manager.select(this->db, select_statement);

        if (ret.size() == 0)
        {
            // we didn't find attacks
            throw AttackException("No attacks found!");
        }

        for (int i = 1; i <= ret.size(); i++)
        {
            /**
             * iterate over all the returned attacks
             */
            attack_data = ret.at(i);
            attack = this->create_attack_from_data(attack_data);

            attacks.push_back(*attack);
        }
    }
    catch (DatabaseException e)
    {
        throw;
    }

    return attacks;
}

void AttackService::create_attack(std::string name,
                                  int damage_dealt,
                                  int endurance_consumption,
                                  int mana_consumption,
                                  std::map<std::string, int> stat_requirements)
{

    std::string insert_statement;
    insert_statement = "INSERT INTO ATTACKS (NAME, DAMAGE_DEALT, ENDURANCE_CONSUMPTION, MANA_CONSUMPTION, STR_REQ, DEX_REQ, INT_REQ, FAITH_REQ)\n"
                       "VALUES('" +
                       name + "', '" + std::to_string(damage_dealt) + "', '" + std::to_string(endurance_consumption) +
                       "', '" + std::to_string(mana_consumption) + "', '" + std::to_string(stat_requirements.at("strength")) +
                       "', '" + std::to_string(stat_requirements.at("dexterity")) + "', '" + std::to_string(stat_requirements.at("inteligence")) +
                       "', '" + std::to_string(stat_requirements.at("faith")) + "');";

    try
    {
        this->database_manager.execute_statement(this->db, insert_statement);
    }
    catch (DatabaseException e)
    {
        throw;
    }
}

void AttackService::delete_attack(Attack attack)
{
    std::string delete_statement;
    std::string id_to_str = std::to_string(attack.get_id());
    delete_statement = "DELETE FROM ATTACKS WHERE ID='" + id_to_str + "';";

    try
    {
        this->database_manager.execute_statement(this->db, delete_statement);
    }
    catch (DatabaseException e)
    {
        throw;
    }
}

void AttackService::update_attack(Attack attack)
{
    std::string update_statement;
    std::string id_to_str = std::to_string(attack.get_id());
    update_statement = "UPDATE ATTACKS SET NAME = '" + attack.get_name() +
                       "', DAMAGE_DEALT = '" + std::to_string(attack.get_damage_dealt()) + "', ENDURANCE_CONSUMPTION = '" +
                       std::to_string(attack.get_endurance_consumption()) + "', MANA_CONSUMPTION = '" + std::to_string(attack.get_mana_consumption()) +
                       "', STR_REQ = '" + std::to_string(attack.get_stat_requirements().at("strength")) +
                       "', DEX_REQ = '" + std::to_string(attack.get_stat_requirements().at("dexterity")) +
                       "', INT_REQ = '" + std::to_string(attack.get_stat_requirements().at("inteligence")) +
                       "', FAITH_REQ = '" + std::to_string(attack.get_stat_requirements().at("faith")) +
                       "' WHERE ID='" + id_to_str + "';";

    try
    {
        this->database_manager.execute_statement(this->db, update_statement);
    }
    catch (DatabaseException e)
    {
        throw;
    }
}