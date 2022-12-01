#ifndef __KNIGHT_H_INCLUDED__
#define __KNIGHT_H_INCLUDED__

#include <character/character.h>

#include <map> //TODO: Remove if unnecessary
#include <string>

/**
 * Knight class
 */
class Knight : public Character
{

    /**
     * Load up all the available attacks from a map structure.
     * Map type must be "std::map<std::string, std::map<std::string, double>>"
     */
    void load_all_attacks();

public:
    /**
     * Initialize a new instance of the Knight class with the given parameters
     *
     * @param[in] name the name of the knight that will be created
     * @param[in] gender the gender of the knight that will be created
     * @param[in] age the age of the knight that will be created
     */
    Knight(std::string name,
           std::string gender,
           int age,
           int level,
           int vigor,
           int endurance,
           int strength,
           int dexterity,
           int inteligence,
           int faith);

    /**
     * Attack another knight and deal certain amount of damage (depletes the enemy's vigor).
     * The attack has certain attribute requirements in order to be executed and consumes stamina.
     *
     * @param[out] enemy the enemy that will be attacked, passed by reference
     * @param[in] atack_name the name of the attack that will be executed
     * @param[in] damage_dealt the amount of damage that will be dealt to the enemy's vigor
     * @param[in] endurance_consumption the amount of endurance that this attack will consume (if enough is available)
     * @param[in] attack_requirements the character attribute requirements of this Knight instance
     *      that are required in order to execute this attack
     */
    // void attack(Character &enemy,
    //             std::string attack_name,
    //             double damage_dealt,
    //             double endurance_consumption,
    //             std::map<std::string, int> attack_requirements);

    void print_knight();
};

#endif