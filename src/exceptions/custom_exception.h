#ifndef __CUSTOM_EXCEPTION_H_INCLUDED__
#define __CUSTOM_EXCEPTION_H_INCLUDED__

#include <exception>

/**
 * A custom exception that gets thrown when an error occurs
 */
class CustomException : public std::exception
{
    char *err_msg;

public:
    CustomException(char *err_msg);
    char *what();
};

#endif