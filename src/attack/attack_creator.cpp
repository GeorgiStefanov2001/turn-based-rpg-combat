#include <attack_creator.h>
#include <attack.h>

void AttackCreator::set_available_attacks(std::map<std::string, std::map<std::string, double>> available_attacks)
{
    this->available_attacks = available_attacks;
}

std::map<std::string, std::map<std::string, double>> AttackCreator::get_available_attacks()
{
    return this->available_attacks;
}

Attack AttackCreator::create_attack(std::string attack_name)
{
}
