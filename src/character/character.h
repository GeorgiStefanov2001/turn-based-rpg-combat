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
     * Constants
     * These multiplier are multiplied by the characters "vigor" and "endurance"
     * attributes which then gives us the vigor and endurance points
     */
    static const int VIGOR_MULTIPLIER = 20;
    static const int ENDURANCE_MULTIPLIER = 15;

    /**
     * Character attributes that get set upon creation
     */
    std::string character_class, name, gender;
    int age, level, vigor, endurance, strength, dexterity, inteligence, faith;

    /**
     * Fields that relate to the dynamically changing character status
     */
    int current_vigor, current_endurance;

    /**
     * A map of maps that contains all the available attacks this class has.
     * Each key of the outer map is the attack name and each value is another map,
     * that contains the attributes of the given attack (such as damage, endurance consumption and so on...)
     */
    std::map<std::string, std::map<std::string, double>> available_attacks;

    // TODO: For mage classes - add "mana" stat and current_mana field
    // TODO: Add current_level + other current_<attribute> as needed
    // (such as current_xp so each win in battle gives xp and we can level up after the fight if the xp >= lvl cap)

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

protected:
    /**
     * Initialize a new instance of the Character class with the given parameters
     *
     * @param[in] character_class the class of the character that will be created
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
     * @param[in] faith the faith attribute of the character that will be created
     */
    Character(std::string character_class,
              std::string name,
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
     * Set the current vigor of the character to a given value
     *
     * @param[in] vigor the value to which the current vigor attribute of this Character instance will be set
     */
    void set_current_vigor(int vigor);

    /**
     * Set the current endurance of the character to a given value
     *
     * @param[in] endurance the value to which the current endurance attribute of this Character instance will be set
     */
    void set_current_endurance(int endurance);

    /**
     * Set the available attacks of the character to a given value
     *
     * @param[in] available_attacks the value to which the available attacks map attribute of this Character instance will be set
     */
    void set_available_attacks(std::map<std::string, std::map<std::string, double>> available_attacks);

public:
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
     * Get the current endurance of the character
     *
     * @returns the current endurance attribute of this Character instance
     */
    int get_current_endurance();

    /**
     * Get the available attacks of the character
     *
     * @returns all the available attacks of this Character instance
     */
    std::map<std::string, std::map<std::string, double>> get_available_attacks();

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