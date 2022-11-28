#include "database_connection_exception.h"

#include <string>

char *
DatabaseConnectionException::what()
{
    return "An error occured when trying to connect to the database. Exiting with non-zero status...";
}