#ifndef __DATABASE_CONNECTION_EXCEPTION_H_INCLUDED__
#define __DATABASE_CONNECTION_EXCEPTION_H_INCLUDED__

#include <exception>

/**
 * A custom exception that gets thrown when an error
 * occurs while trying to connect to the database
 */
class DatabaseConnectionException : public std::exception
{

public:
    char *what();
};

#endif