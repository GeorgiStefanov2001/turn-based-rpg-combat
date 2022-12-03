#include "user_exception.h"

UserException::UserException(char *err_msg)
    : CustomException(err_msg)
{
}