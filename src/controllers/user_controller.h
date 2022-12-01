#ifndef __USER_CONTROLLER_H_INCLUDED__
#define __USER_CONTROLLER_H_INCLUDED__

#include <user/user.h>
#include <services/user_service.h>
#include <database_manager/sqlite_database_manager.h>

#include <sqlite3.h>

#include <list>

class UserController
{
    sqlite3 *db;
    UserService *service;

public:
    UserController(sqlite3 *db, SQLiteDatabaseManager db_manager);

    void list_users();

    User register_user();

    User login_user();

    void delete_user(User logged_user);

    void update_user();
};

#endif