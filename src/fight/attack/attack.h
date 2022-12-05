#ifndef __ATTACK_H_INCLUDED__
#define __ATTACK_H_INCLUDED__

#include <string>
#include <map>

/**
 * Attack class
 */
class Attack
{
    int id, damage_dealt, endurance_consumption, mana_consumption;
    std::string name;
    std::map<std::string, int> stat_requirements;

    /**
     * Overload the operator<< for ostream in order to print out the details of the current Attack instance.
     * Declare it as a friend function so it has access to the private and protected fields of the class that need to be printed.
     * This is done more for demonstrational purposes of the 'friend function' functionality more than anything else.
     *
     * @param[out] s the output stream object that writes the data
     * @param[out] attack the Attack instance, whose data will be printed
     *
     * @returns an std::ostream operator that is used for writing data
     */
    friend std::ostream &operator<<(std::ostream &s, const Attack &attack);

public:
    /**
     * Initialize a new instance of the Attack class with the given parameters
     * @param[in] id the id of the attack
     * @param[in] name the name of the attack that will be created
     * @param[in] damage_dealt how much damage this attack will deal
     * @param[in] endurance_consumption how much endurance this attack will consume
     * @param[in] mana_consumption how much mana this attack will consume
     * @param[in] stat_requirements the Character's stats levels this attack requires in order to be executed
     */
    Attack(int id,
           std::string name,
           int damage_dealt,
           int endurance_consumption,
           int mana_consumption,
           std::map<std::string, int> stat_requirements);

    int get_id();

    std::string get_name();
    void set_name(std::string name);

    int get_damage_dealt();
    void set_damage_dealt(int damage_dealt);

    int get_endurance_consumption();
    void set_endurance_consumption(int endurance_consumption);

    int get_mana_consumption();
    void set_mana_consumption(int mana_consumption);

    std::map<std::string, int> get_stat_requirements();
    void set_stat_requirements(std::map<std::string, int> stat_requirements);
};

#endif