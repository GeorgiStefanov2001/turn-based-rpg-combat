#ifndef __CHARACTER_H_INCLUDED__
#define __CHARACTER_H_INCLUDED__

#include <map>
#include <string>

// Base Character class
class Character
{
    std::string character_class, name, gender;
    int age;
    int level, vigor, endurance, strength, dexterity, inteligence; // Character attributes
    int current_vigor, current_endurance;

    // TODO: For mage classes - add "mana" stat and current_mana field

public:
    Character();
    Character(std::string name, std::string gender, int age, int level, int vigor, int endurance, int strength, int dexterity, int inteligence);
    std::string get_name();
    int get_current_vigor();
    void set_current_vigor(int vigor);
    int get_current_endurance();
    void set_current_endurance(int endurance);
    void attack(Character enemy, std::string attack_name, double damage_dealt, double endurance_consumption, std::map<std::string, int> attack_requirements);
    bool is_alive();
};

#endif