#include "attack.h"

#include <map>
#include <string>

Attack::Attack(
    int id,
    std::string name,
    int damage_dealt,
    int endurance_consumption,
    int mana_consumption,
    std::map<std::string, int> stat_requirements)
{
    this->id = id;
    this->name = name;
    this->damage_dealt = damage_dealt;
    this->endurance_consumption = endurance_consumption;
    this->mana_consumption = mana_consumption;
    this->stat_requirements = stat_requirements;
}

int Attack::get_id()
{
    return this->id;
}

std::string Attack::get_name()
{
    return this->name;
}

void Attack::set_name(std::string name)
{
    this->name = name;
}

int Attack::get_damage_dealt()
{
    return this->damage_dealt;
}

void Attack::set_damage_dealt(int damage_dealt)
{
    this->damage_dealt = damage_dealt;
}

int Attack::get_endurance_consumption()
{
    return this->endurance_consumption;
}

void Attack::set_endurance_consumption(int endurance_consumption)
{
    this->endurance_consumption = endurance_consumption;
}

int Attack::get_mana_consumption()
{
    return this->mana_consumption;
}

void Attack::set_mana_consumption(int mana_consumption)
{
    this->mana_consumption = mana_consumption;
}

std::map<std::string, int> Attack::get_stat_requirements()
{
    return this->stat_requirements;
}

void Attack::set_stat_requirements(std::map<std::string, int> stat_requirements)
{
    this->stat_requirements = stat_requirements;
}