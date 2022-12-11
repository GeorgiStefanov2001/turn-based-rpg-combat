#include "sorcerer.h"
#include <exceptions/attack_exception.h>

#include <iostream>
#include <string>
#include <list>

static const std::list<std::string> SORCERER_AVAILABLE_ATTACKS = {
    "orb_cast",
    "ray_cast",
    "call_from_beyond"};

std::map<std::string, int> Sorcerer::start_attrb = {
    {"level", 6},
    {"vigor", 9},
    {"endurance", 9},
    {"strength", 7},
    {"dexterity", 12},
    {"inteligence", 16},
    {"faith", 7}};

Sorcerer::Sorcerer() : Character()
{
}

Sorcerer::Sorcerer(int id,
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
                   std::string character_class)
    : Character(id,
                character_class,
                name,
                gender,
                age,
                level,
                vigor,
                endurance,
                strength,
                dexterity,
                inteligence,
                faith)
{
    this->set_available_attacks(SORCERER_AVAILABLE_ATTACKS);
}

void Sorcerer::special()
{
    int max_vigor = this->get_vigor() * Character::VIGOR_MULTIPLIER;
    int mana_left = this->get_current_mana() - 130;

    if (this->get_current_vigor() == max_vigor)
    {
        throw AttackException("Current vigor is at max!");
    }
    if (!(mana_left >= 0))
    {
        throw AttackException("Not enough mana to perform special!");
    }

    std::cout << "Healing for 30% of current vigor..." << std::endl;
    this->set_current_mana(mana_left);

    int new_vigor = ((this->get_current_vigor() * 30) / 100) + this->get_current_vigor();

    if (new_vigor > max_vigor)
    {
        new_vigor = max_vigor;
    }
    this->set_current_vigor(new_vigor);
}