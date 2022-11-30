#ifndef __LOGGED_IN_MENU_H_INCLUDED__
#define __LOGGED_IN_MENU_H_INCLUDED__

#include "menu.h"
#include <users/user.h>
#include <database_manager/sqlite_database_manager.h>

#include <sqlite3.h>

class LoggedInMenu : Menu
{

public:
    void display(bool &logged_in, User &user, SQLiteDatabaseManager db_manager, sqlite3 *db);
};

#endif