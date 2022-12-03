#include "attack_exception.h"

AttackException::AttackException(char *err_msg)
    : CustomException(err_msg)
{
}