#include "database_exception.h"

#include <string>

char *
DatabaseException::what()
{
    return "A database-related error occurred. Exiting with non-zero status...";
}