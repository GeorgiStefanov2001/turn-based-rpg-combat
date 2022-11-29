#ifndef __USER_H_INCLUDED__
#define __USER_H_INCLUDED__

#include <string>

class User
{
    int id;
    bool is_admin;
    std::string username, password, first_name, last_name;

public:
    User();

    User(int id, bool is_admin, std::string username, std::string password, std::string first_name, std::string last_name);

    int get_id();

    bool get_is_admin();

    std::string get_username();
    void set_username(std::string username);

    std::string get_password();
    void set_password(std::string password);

    std::string get_first_name();
    void set_first_name(std::string first_name);

    std::string get_last_name();
    void set_last_name(std::string last_name);
};

#endif