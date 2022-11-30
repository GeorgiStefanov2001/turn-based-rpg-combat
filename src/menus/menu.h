#ifndef __MENU_H_INCLUDED__
#define __MENU_H_INCLUDED__

#include <users/user.h>
#include <database_manager/sqlite_database_manager.h>

#include <sqlite3.h>

class Menu
{

public:
    virtual void display(bool &logged_in, User &user, SQLiteDatabaseManager db_manager, sqlite3 *db) = 0;
};

#endif