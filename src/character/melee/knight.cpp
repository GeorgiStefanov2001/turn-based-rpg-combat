#include "knight.h"
#include <exceptions/attack_exception.h>

#include <iostream>
#include <string>
#include <list>

static const std::list<std::string> KNIGHT_AVAILABLE_ATTACKS = {
    "short_slash",
    "long_slash",
    "stab"};

std::map<std::string, int> Knight::start_attrb = {{"level", 9},
                                                  {"vigor", 12},
                                                  {"endurance", 11},
                                                  {"strength", 13},
                                                  {"dexterity", 12},
                                                  {"inteligence", 9},
                                                  {"faith", 9}};

Knight::Knight() : Character()
{
}

Knight::Knight(int id,
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
    this->set_available_attacks(KNIGHT_AVAILABLE_ATTACKS);
}

void Knight::special()
{
    int max_endurance = this->get_endurance() * Character::ENDURANCE_MULTIPLIER;
    int vigor_left = this->get_current_vigor() - 75;

    if (this->get_current_endurance() == max_endurance)
    {
        throw AttackException("Current endurance is at max!");
    }
    if (!(vigor_left >= 0))
    {
        throw AttackException("Using special would decrease health past 0 - suicide is not allowed!");
    }

    std::cout << "Trading for 75 points of current vigor for 30% more stamina..." << std::endl;
    this->set_current_vigor(vigor_left);

    int new_endurance = ((this->get_current_endurance() * 30) / 100) + this->get_current_endurance();

    if (new_endurance > max_endurance)
    {
        new_endurance = max_endurance;
    }
    this->set_current_vigor(new_endurance);
}
