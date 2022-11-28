#include "character/melee/knight.h"
#include "database_manager/sqlite_database_manager.h"
#include "exceptions/database_connection_exception.h"

#include <sqlite3.h>

#include <map>
#include <string>
#include <iostream>

const char *DB_DIR_NAME = "database/turn-based-rpg-combat";

int main()
{
    SQLiteDatabaseManager db_manager;

    try
    {
        sqlite3 *db = db_manager.connect_to_database(DB_DIR_NAME);

        Knight attacker("Gosho", "Male", 50);
        Knight attacked("Pesho", "Male", 231);

        std::cout << attacker << std::endl;

        std::map<std::string, int> attack_req;
        attack_req.insert(std::pair<std::string, int>("Strength", 10));
        attacker.attack(attacked, "slash", 15, 10, attack_req);
        std::cout << attacked.get_current_vigor() << std::endl;

        std::cout << attacker.get_available_attacks().at("short_slash").at("faith_req") << std::endl;

        db_manager.close_database_connection(db);
    }
    catch (DatabaseConnectionException e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}