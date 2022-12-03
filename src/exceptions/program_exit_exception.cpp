#include "program_exit_exception.h"

ProgramExitException::ProgramExitException(char *err_msg)
    : CustomException(err_msg)
{
}