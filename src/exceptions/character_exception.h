#ifndef __CHARACTER_EXCEPTION_H_INCLUDED__
#define __CHARACTER_EXCEPTION_H_INCLUDED__

#include "custom_exception.h"

/**
 * A custom exception that gets thrown when an error
 * occurs while working with the character
 */
class CharacterException : public CustomException
{
public:
    CharacterException(char *err_msg);
};

#endif