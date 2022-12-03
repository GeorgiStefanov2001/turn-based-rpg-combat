#include "database_exception.h"

DatabaseException::DatabaseException(char *err_msg)
    : CustomException(err_msg)
{
}