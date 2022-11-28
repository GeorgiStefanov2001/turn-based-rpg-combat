#ifndef __DATABASE_EXCEPTION_H_INCLUDED__
#define __DATABASE_EXCEPTION_H_INCLUDED__

#include <exception>

/**
 * A custom exception that gets thrown when an error
 * occurs while working with the database
 */
class DatabaseException : public std::exception
{

public:
    char *what();
};

#endif