#ifndef __CHARACTER_H_INCLUDED__
#define __CHARACTER_H_INCLUDED__

#include <map>
#include <string>

/**
 * Base Character class
 */
class Character
{
    /**
     * Character attributes that get set upon creation
     */
    std::string character_class, name, gender;
    int age, level, vigor, endurance, strength, dexterity, inteligence;

    /**
     * Fields that relate to the dynamically changing character status
     */
    int current_vigor, current_endurance;

    // TODO: For mage classes - add "mana" stat and current_mana field

    /**
     * Overload the operator<< for ostream in order to print out the details of the current Character instance.
     * Declare it as a friend function so it has access to the private and protected fields of the class that need to be printed.
     * This is done more for demonstrational purposes of the 'friend function' functionality more than anything else.
     *
     * @param[out] s the output stream object that writes the data
     * @param[out] character the Character instance, whose data will be printed
     *
     * @returns an std::ostream operator that is used for writing data
     */
    friend std::ostream &operator<<(std::ostream &s, const Character &character);

public:
    /**
     * Initialize a new instance of the Character class with the given parameters
     *
     * @param[in] name the name of the character that will be created
     * @param[in] gender the gender of the character that will be created
     * @param[in] age the age of the character that will be created
     * @param[in] level the level of the character that will be created.
     *      Different classes have different starting levels
     * @param[in] vigor the vigor attribute of the character that will be created
     * @param[in] endurance the endurance attribute of the character that will be created
     * @param[in] strength the strength attribute of the character that will be created
     * @param[in] dexterity the dexterity attribute of the character that will be created
     * @param[in] inteligence the inteligence attribute of the character that will be created
     */
    Character(std::string name,
              std::string gender,
              int age,
              int level,
              int vigor,
              int endurance,
              int strength,
              int dexterity,
              int inteligence);

    // TODO: Add getter/setter for character_class; setter will be used in the constructors of the children classes

    /**
     * Get the name of the character
     *
     * @returns the name of this Character instance as a string
     */
    std::string get_name();

    /**
     * Get the current vigor of the character
     *
     * @returns the current vigor attribute of this Character instance
     */
    int get_current_vigor();

    /**
     * Set the current vigor of the character to a given value
     *
     * @param vigor the value to which the current vigor attribute of this Character instance will be set
     */
    void set_current_vigor(int vigor);

    /**
     * Get the current endurance of the character
     *
     * @returns the current endurance attribute of this Character instance
     */
    int get_current_endurance();

    /**
     * Set the current endurance of the character to a given value
     *
     * @param endurance the value to which the current endurance attribute of this Character instance will be set
     */
    void set_current_endurance(int endurance);

    /**
     * Attack another character and deal certain amount of damage (depletes the enemy's vigor).
     * The attack has certain attribute requirements in order to be executed and consumes stamina.
     *
     * @param[out] enemy the enemy that will be attacked, passed by reference
     * @param[in] atack_name the name of the attack that will be executed
     * @param[in] damage_dealt the amount of damage that will be dealt to the enemy's vigor
     * @param[in] endurance_consumption the amount of endurance that this attack will consume (if enough is available)
     * @param[in] attack_requirements the character attribute requirements of this Character instance
     *      that are required in order to execute this attack
     */
    void attack(Character &enemy,
                std::string attack_name,
                double damage_dealt,
                double endurance_consumption,
                std::map<std::string, int> attack_requirements);

    /**
     * Check whether the character is alive (the current vigor they have must be positive)
     *
     * @returns true if the character is alive, otherwise false
     */
    bool is_alive();
};

#endif