#ifndef __program_exit_exception_H_INCLUDED__
#define __program_exit_exception_H_INCLUDED__

#include "custom_exception.h"

/**
 * A custom exception that gets used for manipulating program state
 */
class ProgramExitException : public CustomException
{
public:
    ProgramExitException(char *err_msg);
};

#endif