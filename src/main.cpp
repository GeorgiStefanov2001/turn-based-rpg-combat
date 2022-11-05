#include "character/character.h"

#include <map>
#include <string>
#include <iostream>

int main()
{
    Character attacker("Gosho", "Male", 12, 12, 12, 25, 12, 12, 12);
    Character attacked("Pesho", "Male", 12, 12, 300, 12, 12, 12, 12);
    std::map<std::string, int> attack_req;
    attack_req.insert(std::pair<std::string, int>("Strength", 10));
    attacker.attack(attacked, "slash", 200, 10, attack_req);

    std::cout << attacked.get_current_vigor() << std::endl;

    return 0;
}