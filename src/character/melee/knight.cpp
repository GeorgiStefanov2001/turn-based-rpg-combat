#include "knight.h"

#include <iostream>
#include <string>
#include <list>

static const std::list<std::string> KNIGHT_AVAILABLE_ATTACKS = {
    "short_slash",
    "long_slash",
    "stab"};

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
               int faith)
    : Character(id,
                "Knight",
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