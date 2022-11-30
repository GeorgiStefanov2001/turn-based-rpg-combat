#include "program_exit_exception.h"

#include <string>

ProgramExitException::ProgramExitException(char *err_msg)
{
    this->err_msg = err_msg;
}

char *
ProgramExitException::what()
{
    return this->err_msg;
}