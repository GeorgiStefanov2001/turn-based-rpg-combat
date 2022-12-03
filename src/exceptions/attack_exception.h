#ifndef __ATTACK_EXCEPTION_H_INCLUDED__
#define __ATTACK_EXCEPTION_H_INCLUDED__

#include "custom_exception.h"

/**
 * A custom exception that gets thrown when an error
 * occurs while working with the attacks
 */
class AttackException : public CustomException
{
public:
    AttackException(char *err_msg);
};

#endif