#include "attack_controller.h"
#include <fight/attack/attack.h>
#include <services/attack_service.h>
#include <database_manager/sqlite_database_manager.h>
#include <exceptions/database_exception.h>
#include <exceptions/attack_exception.h>

#include <iostream>
#include <string>
#include <list>
#include <map>

AttackController::AttackController(sqlite3 *db, SQLiteDatabaseManager db_manager)
{
    this->db = db;
    this->attack_service = new AttackService(db_manager, this->db);
}

void AttackController::input_attack_stats(int &damage_dealt,
                                          int &endurance_consumption,
                                          int &mana_consumption,
                                          int &str_req,
                                          int &dex_req,
                                          int &int_req,
                                          int &faith_req,
                                          bool is_update)
{
    std::string update_info_for_int = is_update ? " <enter '-1' to keep current>" : "";

    /**
     * Beauty incoming :)
     * I just want personalized cout messages otherwise could make it into a method
     */
    do
    {
        std::cout << "Enter the damage the attack deals (>0)" + update_info_for_int + ": ";
        std::cin >> damage_dealt;
    } while (is_update ? (damage_dealt == 0 || damage_dealt < -1) : (damage_dealt <= 0));
    do
    {
        std::cout << "Enter the endurance the attack consumes (>=0)" + update_info_for_int + ": ";
        std::cin >> endurance_consumption;
    } while (is_update ? (endurance_consumption < -1) : (endurance_consumption < 0));
    do
    {
        std::cout << "Enter the mana the attack consumes (>=0)" + update_info_for_int + ": ";
        std::cin >> mana_consumption;
    } while (is_update ? (mana_consumption < -1) : (mana_consumption < 0));
    do
    {
        std::cout << "Enter the strength requirement of the attack (>=0)" + update_info_for_int + ": ";
        std::cin >> str_req;
    } while (is_update ? (str_req < -1) : (str_req < 0));
    do
    {
        std::cout << "Enter the dexterity requirement of the attack (>=0)" + update_info_for_int + ": ";
        std::cin >> dex_req;
    } while (is_update ? (dex_req < -1) : (dex_req < 0));
    do
    {
        std::cout << "Enter the inteligence requirement of the attack (>=0)" + update_info_for_int + ": ";
        std::cin >> int_req;
    } while (is_update ? (int_req < -1) : (int_req < 0));
    do
    {
        std::cout << "Enter the faith requirement of the attack (>=0)" + update_info_for_int + ": ";
        std::cin >> faith_req;
    } while (is_update ? (faith_req < -1) : (faith_req < 0));
}

void AttackController::create_attack()
{
    std::string name;
    int damage_dealt = -1, end_consumption = -1, mana_consumption = -1, str_req = -1, dex_req = -1, int_req = -1, faith_req = -1;
    std::map<std::string, int> stat_req;

    std::cout << "\nCreate a new attack\n"
              << std::endl;

    std::cout << "Enter attack name: ";
    std::cin >> name;

    bool attack_exists = true;
    try
    {
        this->attack_service->get_attack(name);
    }
    catch (AttackException e)
    {
        // attack doesnt't exist, we can continue
        attack_exists = false;
    }

    if (!attack_exists)
    {
        this->input_attack_stats(
            damage_dealt,
            end_consumption,
            mana_consumption,
            str_req,
            dex_req,
            int_req,
            faith_req,
            false);
        stat_req.insert({"strength", str_req});
        stat_req.insert({"dexterity", dex_req});
        stat_req.insert({"inteligence", int_req});
        stat_req.insert({"faith", faith_req});

        try
        {
            this->attack_service->create_attack(name, damage_dealt, end_consumption, mana_consumption, stat_req);
            std::cout << "\nAttack " << name << " created successfully!\n"
                      << std::endl;
            std::cout << "* - * - *\n";
        }
        catch (DatabaseException e)
        {
            throw;
        }
        catch (AttackException e)
        {
            throw;
        }
    }
    else
    {
        throw AttackException("Attack with given name already exists!");
    }
}

void AttackController::list_attacks()
{
    std::cout << "\nListing all attacks in the database...\n"
              << std::endl;

    try
    {
        std::list<Attack> attacks = this->attack_service->list_attacks();

        for (const auto &attack : attacks)
        {
            /**
             * Good thing we overwrote the << operator :)
             */
            std::cout << attack << std::endl;
        }
        std::cout << "\n";
        std::cout << "* - * - *\n"
                  << std::endl;
    }
    catch (DatabaseException e)
    {
        throw;
    }
    catch (AttackException e)
    {
        throw;
    }
}

void AttackController::delete_attack()
{
    std::string name;
    std::cout << "\nDelete an attack\n"
              << std::endl;
    std::cout << "Enter name of the attack you wish to delete: ";
    std::cin >> name;

    try
    {
        Attack attack = this->attack_service->get_attack(name);
        this->attack_service->delete_attack(attack);
        std::cout << "\nAttack " << name << " deleted successfully!\n"
                  << std::endl;
        std::cout << "* - * - *\n"
                  << std::endl;
    }
    catch (DatabaseException e)
    {
        throw;
    }
    catch (AttackException e)
    {
        throw;
    }
}

void AttackController::update_attack()
{
    std::string name, new_name;
    int new_deamage_dealt, new_end_consumption, new_mana_consumption, new_str_req, new_dex_req, new_int_req, new_faith_req;
    std::cout << "\nUpdate attacks's stats\n"
              << std::endl;
    std::cout << "Enter name of the attack you wish to update: ";
    std::cin >> name;

    try
    {
        Attack attack = this->attack_service->get_attack(name);

        std::cout << "Enter the new name of the attack <enter 'same' to keep current>: ";
        std::cin >> new_name;

        this->input_attack_stats(
            new_deamage_dealt,
            new_end_consumption,
            new_mana_consumption,
            new_str_req,
            new_dex_req,
            new_int_req,
            new_faith_req,
            true);
        /**
         * Extremely beautiful logic follows :)
         */
        new_name = (new_name.compare("same") == 0) ? attack.get_name() : new_name;
        new_deamage_dealt = (new_deamage_dealt == -1) ? attack.get_damage_dealt() : new_deamage_dealt;
        new_end_consumption = (new_end_consumption == -1) ? attack.get_endurance_consumption() : new_end_consumption;
        new_mana_consumption = (new_mana_consumption == -1) ? attack.get_mana_consumption() : new_mana_consumption;
        new_str_req = (new_str_req == -1) ? attack.get_stat_requirements().at("strength") : new_str_req;
        new_dex_req = (new_dex_req == -1) ? attack.get_stat_requirements().at("dexterity") : new_dex_req;
        new_int_req = (new_int_req == -1) ? attack.get_stat_requirements().at("inteligence") : new_int_req;
        new_faith_req = (new_faith_req == -1) ? attack.get_stat_requirements().at("faith") : new_faith_req;

        std::map<std::string, int> attack_reqs;
        attack_reqs.insert({"strength", new_str_req});
        attack_reqs.insert({"dexterity", new_dex_req});
        attack_reqs.insert({"inteligence", new_int_req});
        attack_reqs.insert({"faith", new_faith_req});

        attack.set_name(new_name);
        attack.set_damage_dealt(new_deamage_dealt);
        attack.set_endurance_consumption(new_end_consumption);
        attack.set_mana_consumption(new_mana_consumption);
        attack.set_stat_requirements(attack_reqs);

        this->attack_service->update_attack(attack);
        std::cout << "\nAttack " << name << " updated successfully!\n"
                  << std::endl;
        std::cout << "* - * - *\n"
                  << std::endl;
    }
    catch (DatabaseException e)
    {
        throw;
    }
    catch (AttackException e)
    {
        throw;
    }
}