#include "character_exception.h"

#include <string>

CharacterException::CharacterException(char *err_msg)
{
    this->err_msg = err_msg;
}

char *
CharacterException::what()
{
    return this->err_msg;
}