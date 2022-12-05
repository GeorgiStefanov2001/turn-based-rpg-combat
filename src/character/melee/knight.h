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
public:
    /**
     * Initialize a new instance of the Knight class with the given parameters
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
    Knight(int id,
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
};

#endif