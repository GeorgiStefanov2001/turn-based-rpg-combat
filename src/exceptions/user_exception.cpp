#include "user_exception.h"

#include <string>

UserException::UserException(char *err_msg)
{
    this->err_msg = err_msg;
}

char *
UserException::what()
{
    return this->err_msg;
}