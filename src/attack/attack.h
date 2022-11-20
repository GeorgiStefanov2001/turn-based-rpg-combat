#ifndef __ATTACK_H_INCLUDED__
#define __ATTACK_H_INCLUDED__

#include <string>
#include <map>

/**
 * Attack class
 */
class Attack
{
    std::string name;
    double damage_dealt, endurance_consumption;
    std::map<std::string, double> stat_requirements;

public:
    /**
     * Initialize a new instance of the Attack class with the given parameters
     * @param[in] name the name of the attack that will be created
     * @param[in] damage_dealt how much damage this attack will deal
     * @param[in] endurance_consumption how much endurance this attack will consume
     * @param[in] stat_requirements the Character's stats levels this attack requires in order to be executed
     */
    Attack(std::string name,
           double damage_dealt,
           double endurance_consumption,
           std::map<std::string, double> stat_requirements);
};
#endif