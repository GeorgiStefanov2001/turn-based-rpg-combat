#include <attack.h>

Attack::Attack(std::string name,
               double damage_dealt,
               double endurance_consumption,
               std::map<std::string, double> stat_requirements)
{
    this->name = name;
    this->damage_dealt = damage_dealt;
    this->endurance_consumption = endurance_consumption;
    this->stat_requirements = stat_requirements;
}