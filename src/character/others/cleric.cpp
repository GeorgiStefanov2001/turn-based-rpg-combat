#include "cleric.h"

#include <iostream>
#include <string>
#include <list>

static const std::list<std::string> CLERIC_AVAILABLE_ATTACKS = {
    "short_slash",
    "long_slash",
    "orb_Cast"};

std::map<std::string, int> Cleric::start_attrb = {{"level", 7},
                                                  {"vigor", 10},
                                                  {"endurance", 14},
                                                  {"strength", 12},
                                                  {"dexterity", 8},
                                                  {"inteligence", 13},
                                                  {"faith", 16}};

Cleric::Cleric()
{
}

Cleric::Cleric(int id,
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
    : Sorcerer(id,
               name,
               gender,
               age,
               level,
               vigor,
               endurance,
               strength,
               dexterity,
               inteligence,
               faith,
               character_class = character_class),
      Character(id,
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
    this->set_available_attacks(CLERIC_AVAILABLE_ATTACKS);
}