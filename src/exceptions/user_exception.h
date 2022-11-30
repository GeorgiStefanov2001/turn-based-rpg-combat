#ifndef __USER_EXCEPTION_H_INCLUDED__
#define __USER_EXCEPTION_H_INCLUDED__

#include <exception>

/**
 * A custom exception that gets thrown when an error
 * occurs while working with the user
 */
class UserException : public std::exception
{

public:
    char *what();
};

#endif