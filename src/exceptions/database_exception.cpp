#include "database_exception.h"

#include <string>

DatabaseException::DatabaseException(char *err_msg)
{
    this->err_msg = err_msg;
}

char *
DatabaseException::what()
{
    return "A database-related error occurred. Exiting with non-zero status...";
}