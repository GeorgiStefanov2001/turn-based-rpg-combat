#include "custom_exception.h"

CustomException::CustomException(char *err_msg)
{
    this->err_msg = err_msg;
}

char *
CustomException::what()
{
    return this->err_msg;
}