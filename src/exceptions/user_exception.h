#ifndef __USER_EXCEPTION_H_INCLUDED__
#define __USER_EXCEPTION_H_INCLUDED__

#include "custom_exception.h"

/**
 * A custom exception that gets thrown when an error
 * occurs while working with the user
 */
class UserException : public CustomException
{
public:
    UserException(char *err_msg);
};

#endif