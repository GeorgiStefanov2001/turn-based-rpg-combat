#include "character/melee/knight.h"

#include <map>
#include <string>
#include <iostream>

int main()
{
    Knight attacker("Gosho", "Male", 50);
    Knight attacked("Pesho", "Male", 231);

    std::cout << attacker << std::endl;

    std::map<std::string, int> attack_req;
    attack_req.insert(std::pair<std::string, int>("Strength", 10));
    attacker.attack(attacked, "slash", 15, 10, attack_req);
    std::cout << attacked.get_current_vigor() << std::endl;

    std::cout << attacker.get_available_attacks().at("short_slash").at("faith_req") << std::endl;

    return 0;
}