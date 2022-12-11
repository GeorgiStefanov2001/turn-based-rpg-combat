#ifndef __CHARACTER_H_INCLUDED__
#define __CHARACTER_H_INCLUDED__

#include <fight/attack/attack.h>

#include <map>
#include <string>
#include <list>

/**
 * Base Character class
 */
class Character
{
    /**
     * Character attributes that get set upon creation
     */
    std::string character_class, name, gender;
    int id, age, level, vigor, endurance, strength, dexterity, inteligence, faith;

    /**
     * Fields that relate to the dynamically changing character status
     */
    int current_vigor, current_endurance, current_mana, current_xp;

    /**
     * A list of strings that contains all the available attacks this class has.
     */
    std::list<std::string> available_attacks;

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
     * Constants
     * These multiplier are multiplied by the characters "vigor" and "endurance"
     * attributes which then gives us the vigor and endurance points
     */
    static const int VIGOR_MULTIPLIER = 20;
    static const int ENDURANCE_MULTIPLIER = 15;
    static const int MANA_MULTIPLIER = 15;

    Character();
    /**
     * Initialize a new instance of the Character class with the given parameters
     *
     * @param[in] id the id of the character that will be created
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
    Character(int id,
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
     * Set the current mana of the character to a given value
     *
     * @param[in] mana the value to which the current mana attribute of this Character will be set
     */
    void set_current_mana(int mana);

    /**
     * Set the current xp of the character to a given value
     *
     * @param[in] xp the value to which the current xp attribute of this Character instance will be set
     */
    void set_current_xp(int xp);

    /**
     * Set the available attacks of the character to a given value
     *
     * @param[in] available_attacks the value to which the available attacks attribute of this Character instance will be set
     */
    void set_available_attacks(std::list<std::string> available_attacks);

public:
    /**
     * Get the id of the character
     *
     * @returns the id of this Character instance
     */
    int get_id();

    /**
     * Get the name of the character
     *
     * @returns the name of this Character instance as a string
     */
    std::string get_name();

    void set_name(std::string name);

    /**
     * Get the gender of the character
     *
     * @returns the gender of this Character instance as a string
     */
    std::string get_gender();

    void set_gender(std::string gender);

    /**
     * Get the age of the character
     *
     * @returns the age of this Character instance as a string
     */
    int get_age();

    void set_age(int age);

    int get_vigor();

    void set_vigor(int vigor);

    int get_endurance();

    void set_endurance(int endurance);

    int get_strength();

    void set_strength(int strength);

    int get_dexterity();

    void set_dexterity(int dexterity);

    int get_inteligence();

    void set_inteligence(int inteligence);

    int get_faith();

    void set_faith(int faith);

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
     * Get the current mana of the character
     *
     * @returns the current mana attribute of this Character instance
     */
    int get_current_mana();

    /**
     * Get the current xp of the character
     *
     * @returns the current xp attribute of this Character instance
     */
    int get_current_xp();

    /**
     * Get the available attacks of the character
     *
     * @returns all the available attacks of this Character instance
     */
    std::list<std::string> get_available_attacks();

    /**
     * Attack another character and deal certain amount of damage (depletes the enemy's vigor).
     * The attack has certain attribute requirements in order to be executed and consumes stamina/mana.
     *
     * @param[out] enemy the enemy that will be attacked, passed by reference
     * @param[in] attack the attack that will be executed
     */
    void attack(Character &enemy, Attack attack);

    /**
     * Check whether the character is alive (the current vigor they have must be positive)
     *
     * @returns true if the character is alive, otherwise false
     */
    bool is_alive();

    bool meets_attack_reqs(Attack attack);

    virtual void special() = 0;

    void forfeit();
};

#endif