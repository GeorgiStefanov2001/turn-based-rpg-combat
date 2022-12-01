#ifndef __CHARACTER_EXCEPTION_H_INCLUDED__
#define __CHARACTER_EXCEPTION_H_INCLUDED__

#include <exception>

/**
 * A custom exception that gets thrown when an error
 * occurs while working with the character
 */
class CharacterException : public std::exception
{
    char *err_msg;

public:
    CharacterException(char *err_msg);
    char *what();
};

#endif