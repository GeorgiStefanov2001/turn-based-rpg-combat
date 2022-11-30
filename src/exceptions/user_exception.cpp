#include "user_exception.h"

#include <string>

char *
UserException::what()
{
    return "A user-related error occurred. Exiting with non-zero status...";
}