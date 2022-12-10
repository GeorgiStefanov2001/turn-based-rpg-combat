#include "sorcerer.h"

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
    this->current_mana = (inteligence * this->MANA_MULTIPLIER);
}

int Sorcerer::get_current_mana()
{
    return this->current_mana;
}

void Sorcerer::set_current_mana(int mana)
{
    this->current_mana = current_mana;
}

void Sorcerer::special()
{
    std::cout << "i am sorcerer" << std::endl;
}