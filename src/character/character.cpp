#include "character.h"

#include <iostream>

Character::Character(std::string character_class,
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
{
    this->character_class = character_class;
    this->name = name;
    this->gender = gender;
    this->age = age;
    this->level = level;
    this->vigor = vigor;
    this->endurance = endurance;
    this->strength = strength;
    this->dexterity = dexterity;
    this->inteligence = inteligence;
    this->faith = faith;
    this->current_vigor = (vigor * this->VIGOR_MULTIPLIER);
    this->current_endurance = (endurance * this->ENDURANCE_MULTIPLIER);
}

std::string Character::get_name()
{
    return this->name;
}

int Character::get_current_vigor()
{
    return this->current_vigor;
}

void Character::set_current_vigor(int vigor)
{
    this->current_vigor = vigor;
}

int Character::get_current_endurance()
{
    return this->current_endurance;
}

void Character::set_current_endurance(int endurance)
{
    this->current_endurance = endurance;
}

std::map<std::string, std::map<std::string, double>> Character::get_available_attacks()
{
    return this->available_attacks;
}

void Character::set_available_attacks(std::map<std::string, std::map<std::string, double>> available_attacks)
{
    this->available_attacks = available_attacks;
}

void Character::attack(Character &enemy,
                       std::string attack_name,
                       double damage_dealt,
                       double endurance_consumption,
                       std::map<std::string, int> attack_requirements)
{
    // TODO: Check for attack requirements !!!
    int endurance_left = this->get_current_endurance() - endurance_consumption;
    if (endurance_left >= 0)
    {
        this->set_current_endurance(endurance_left);
        std::cout << this->name << " attacks " << enemy.get_name() << "(attack_name: " << attack_name << ", damage_dealt: " << damage_dealt << ");" << std::endl;
        enemy.set_current_vigor(enemy.get_current_vigor() - damage_dealt);
    }
    else
    {
        std::cout << "Not enough endurance to perform this attack!" << std::endl;
    }
}

bool Character::is_alive()
{
    return this->get_current_vigor() >= 0;
}

std::ostream &operator<<(std::ostream &s, const Character &character)
{
    // TODO: Print the character information in a readable fashion
    // TODO: When fighting, in the main loop print character details (the remaining vigor, endurance, mana)
    return s << character.name << ", " << character.age;
}