#include "knight.h"

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