#ifndef __program_exit_exception_H_INCLUDED__
#define __program_exit_exception_H_INCLUDED__

#include <exception>

/**
 * A custom exception that gets used for manipulating program state
 */
class ProgramExitException : public std::exception
{
    char *err_msg;

public:
    ProgramExitException(char *err_msg);
    char *what();
};

#endif