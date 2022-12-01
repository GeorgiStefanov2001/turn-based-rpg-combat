#ifndef __USER_SERVICE_H_INCLUDED__
#define __USER_SERVICE_H_INCLUDED__

#include <user/user.h>
#include <database_manager/sqlite_database_manager.h>

#include <sqlite3.h>

#include <string>
#include <list>

class UserService
{
    SQLiteDatabaseManager database_manager;
    sqlite3 *db;

public:
    UserService(SQLiteDatabaseManager database_manager, sqlite3 *db);

    User get_user(std::string username);

    std::list<User> list_users();

    void create_user(std::string username,
                     std::string password,
                     std::string first_name,
                     std::string last_name);

    void delete_user(User user);

    void update_user(User user);
};

#endif