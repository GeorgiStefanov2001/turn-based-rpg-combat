#ifndef __CLERIC_H_INCLUDED__
#define __CLERIC_H_INCLUDED__

#include <character/melee/knight.h>
#include <character/mage/sorcerer.h>

#include <string>

/**
 * Cleric class
 */
class Cleric : public Knight, public Sorcerer
{
protected:
    Cleric();

public:
    /**
     * Starting attributes of the Cleric class
     */

    static std::map<std::string, int> start_attrb;

    /**
     * Initialize a new instance of the Cleric class with the given parameters
     *
     * @param[in] id the id of the character that will be created
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
    Cleric(int id,
           std::string name,
           std::string gender,
           int age,
           int level,
           int vigor,
           int endurance,
           int strength,
           int dexterity,
           int inteligence,
           int faith,
           std::string character_class = "Cleric");
};

#endif