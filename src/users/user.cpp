#include "user.h"

#include <string>

User::User(bool is_admin, std::string username, std::string password, std::string first_name, std::string last_name)
{
    this->is_admin = is_admin;
    this->username = username;
    this->password = password;
    this->first_name = first_name;
    this->last_name = last_name;
}

bool User::get_is_admin()
{
    return this->is_admin;
}

std::string User::get_username()
{
    return this->username;
}

void User::set_username(std::string username)
{
    this->username = username;
}

std::string User::get_password()
{
    return this->password;
}

void User::set_password(std::string password)
{
    this->password = password;
}

std::string User::get_first_name()
{
    return this->first_name;
}

void User::set_first_name(std::string first_name)
{
    this->first_name = first_name;
}

std::string User::get_last_name()
{
    return this->last_name;
}

void User::set_last_name(std::string last_name)
{
    this->last_name = last_name;
}