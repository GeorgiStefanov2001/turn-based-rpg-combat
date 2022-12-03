#include "character_exception.h"

CharacterException::CharacterException(char *err_msg)
    : CustomException(err_msg)
{
}