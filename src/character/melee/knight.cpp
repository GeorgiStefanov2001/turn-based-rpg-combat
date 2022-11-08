#include "knight.h"

Knight::Knight(std::string name, std::string gender, int age)
    : Character("Knight",
                name,
                gender,
                age,
                this->starting_attributes::level,
                this->starting_attributes::vigor,
                this->starting_attributes::endurance,
                this->starting_attributes::strength,
                this->starting_attributes::dexterity,
                this->starting_attributes::inteligence,
                this->starting_attributes::faith)
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