#ifndef __DATABASE_EXCEPTION_H_INCLUDED__
#define __DATABASE_EXCEPTION_H_INCLUDED__

#include "custom_exception.h"

/**
 * A custom exception that gets thrown when an error
 * occurs while working with the database
 */
class DatabaseException : public CustomException
{

public:
    DatabaseException(char *err_msg);
};

#endif