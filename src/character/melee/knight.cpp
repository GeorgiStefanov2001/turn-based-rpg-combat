#include "knight.h"

Knight::Knight(std::string name, std::string gender, int age)
    : Character("Knight",
                name,
                gender,
                age,
                this->starting_attributes::level,
                this->starting_attributes::vigor,
                this->starting_attributes::endurance,
                this->starting_attributes::strength,
                this->starting_attributes::dexterity,
                this->starting_attributes::inteligence,
                this->starting_attributes::faith)
{
}