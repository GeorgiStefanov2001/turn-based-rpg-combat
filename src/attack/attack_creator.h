#ifndef __ATTACK_CREATOR_H_INCLUDED__
#define __ATTACK_CREATOR_H_INCLUDED__

#include <string>
#include <map>

#include <attack.h>

/**
 * AttackCreator class that will create an Attack object based on a given attack name
 */
class AttackCreator
{
    std::map<std::string, std::map<std::string, double>> available_attacks;

    /**
     * Load up all the available attacks from a map structure
     *
     * @param[in] available_attacks the map, containing all available attacks and their characteristics
     */
    void set_available_attacks(std::map<std::string, std::map<std::string, double>> available_attacks);

    /**
     * Return all available attacks as a map structure
     *
     * @returns the map structure, containing all available attacks and their characteristics
     */
    std::map<std::string, std::map<std::string, double>> get_available_attacks();

public:
    /**
     * Create an Attack object based on a given name, populate its fields with correct data and return it
     *
     * @param[in] name the name of the attack that will be created
     *
     * @returns an Attack object
     */
    Attack create_attack(std::string attack_name);
};
#endif