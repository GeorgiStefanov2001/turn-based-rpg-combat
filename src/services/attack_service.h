#ifndef __ATTACK_SERVICE_H_INCLUDED__
#define __ATTACK_SERVICE_H_INCLUDED__

#include <fight/attack/attack.h>
#include <database_manager/sqlite_database_manager.h>

#include <sqlite3.h>

#include <string>
#include <list>
#include <map>

class AttackService
{
    SQLiteDatabaseManager database_manager;
    sqlite3 *db;

public:
    AttackService(SQLiteDatabaseManager database_manager, sqlite3 *db);

    Attack *create_attack_from_data(std::map<std::string, std::string> attack_data);

    Attack get_attack(std::string name);

    std::list<Attack> list_attacks();

    void create_attack(std::string name,
                       int damage_dealt,
                       int endurance_consumption,
                       int mana_consumption,
                       std::map<std::string, int> stat_requirements);

    void delete_attack(Attack attack);

    void update_attack(Attack attack);
};

#endif