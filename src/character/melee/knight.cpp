#include "knight.h"

#include <iostream>

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
    this->load_all_attacks();
}

static const std::map<std::string, std::map<std::string, double>> KNIGHT_AVAILABLE_ATTACKS = {
    {"short_slash",
     {{"damage_dealt", 20},
      {"endurance_consumption", 30},
      {"strength_req", 13},
      {"dexterity_req", 12},
      {"inteligence_req", 0},
      {"faith_req", 0}}},
    {"stab",
     {{"damage_dealt", 15},
      {"endurance_consumption", 20},
      {"strength_req", 13},
      {"dexterity_req", 12},
      {"inteligence_req", 0},
      {"faith_req", 0}}},
    {"long_slash",
     {{"damage_dealt", 35},
      {"endurance_consumption", 50},
      {"strength_req", 13},
      {"dexterity_req", 12},
      {"inteligence_req", 0},
      {"faith_req", 0}}}};

void Knight::load_all_attacks()
{
    this->set_available_attacks(KNIGHT_AVAILABLE_ATTACKS);
}

void Knight::print_knight()
{
    std::cout << "i am knight";
}