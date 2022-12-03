#ifndef __ATTACK_CONTROLLER_H_INCLUDED__
#define __ATTACK_CONTROLLER_H_INCLUDED__

#include <fight/attack/attack.h>
#include <services/attack_service.h>
#include <database_manager/sqlite_database_manager.h>

#include <sqlite3.h>

#include <list>

class AttackController
{
    sqlite3 *db;
    AttackService *attack_service;

public:
    AttackController(sqlite3 *db, SQLiteDatabaseManager db_manager);

    void list_attacks();

    void create_attack();

    void delete_attack();

    void update_attack();
};

#endif