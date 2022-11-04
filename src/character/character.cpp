#include "character.h"

#include <iostream>

Character::Character() {}

Character::Character(std::string name, std::string gender, int age, int level, int vigor, int endurance, int strength, int dexterity, int inteligence)
{
    // Creating a new character

    this->name = name;
    this->gender = gender;
    this->age = age;
    this->level = level;
    this->vigor = vigor;
    this->endurance = endurance;
    this->strength = strength;
    this->dexterity = dexterity;
    this->inteligence = inteligence;
    this->set_current_vigor(this->vigor);
    this->set_current_endurance(this->endurance);
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

void Character::attack(Character enemy, std::string attack_name, double damage_dealt, double endurance_consumption, std::map<std::string, int> attack_requirements)
{
    // TODO: When fighting, in the main loop print character details (the remaining vigor, endurance, mana)
    int endurance_left = this->get_current_endurance() - endurance_consumption;
    if (endurance_left >= 0)
    {
        this->set_current_endurance(endurance_left);
        std::cout << this->name << " attacks " << enemy.get_name() << "(attack_name: " << attack_name << ", damage_dealt: " << damage_dealt << ");" << std::endl;
        enemy.set_current_vigor(enemy.get_current_vigor() - damage_dealt);

        if (enemy.get_current_vigor() <= 0)
        {
            std::cout << enemy.get_name() << " has died! " << this->get_name() << " wins!" << std::endl;
            // TODO: signalize that the enemy has died upwards in the main loop and handle this logic there
            // one way is to have a method in the character "is_alive()" and poll the attacked after each attack - would be best I think
        }
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