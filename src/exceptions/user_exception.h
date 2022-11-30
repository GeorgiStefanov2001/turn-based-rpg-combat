#ifndef __USER_EXCEPTION_H_INCLUDED__
#define __USER_EXCEPTION_H_INCLUDED__

#include <exception>

/**
 * A custom exception that gets thrown when an error
 * occurs while working with the user
 */
class UserException : public std::exception
{
    char *err_msg;

public:
    UserException(char *err_msg);
    char *what();
};

#endif