#include "character.h"
#include <fight/attack/attack.h>

#include <iostream>
#include <string>
#include <list>

Character::Character()
{
}

Character::Character(int id,
                     std::string character_class,
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
    this->id = id;
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

int Character::get_id()
{
    return this->id;
}

std::string Character::get_name()
{
    return this->name;
}

void Character::set_name(std::string name)
{
    this->name = name;
}

std::string Character::get_gender()
{
    return this->gender;
}

void Character::set_gender(std::string gender)
{
    this->gender = gender;
}

int Character::get_age()
{
    return this->age;
}

void Character::set_age(int age)
{
    this->age = age;
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

int Character::get_current_xp()
{
    return this->current_xp;
}

void Character::set_current_xp(int xp)
{
    this->current_xp = xp;
}

std::list<std::string> Character::get_available_attacks()
{
    return this->available_attacks;
}

void Character::set_available_attacks(std::list<std::string> available_attacks)
{
    this->available_attacks = available_attacks;
}

// void Character::attack(Character &enemy,
//                        Attack attack)
// {
//     int endurance_left = this->get_current_endurance() - endurance_consumption;
//     if (endurance_left >= 0)
//     {
//         this->set_current_endurance(endurance_left);
//         std::cout << this->name << " attacks " << enemy.get_name() << "(attack_name: " << attack_name << ", damage_dealt: " << damage_dealt << ");" << std::endl;
//         enemy.set_current_vigor(enemy.get_current_vigor() - damage_dealt);
//     }
//     else
//     {
//         std::cout << "Not enough endurance to perform this attack!" << std::endl;
//     }
// }

bool Character::is_alive()
{
    return this->get_current_vigor() >= 0;
}

std::ostream &operator<<(std::ostream &s, const Character &character)
{
    return s << "- " << character.name << ": " << character.character_class << ", lvl "
             << character.level << ", gender: " << character.gender << ", age: " << character.age << ".\n"
             << "   Stats: VIG:" << character.vigor << ", END: " << character.endurance
             << ", STR: " << character.strength << ", DEX: " << character.dexterity
             << ", INT: " << character.inteligence << ", FAITH: " << character.faith << ".";
}