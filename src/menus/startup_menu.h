#ifndef __STARTUP_MENU_H_INCLUDED__
#define __STARTUP_MENU_H_INCLUDED__

#include "menu.h"
#include <user/user.h>
#include <database_manager/sqlite_database_manager.h>

#include <sqlite3.h>

class StartupMenu : Menu
{

public:
    void display(bool &logged_in, User &user, SQLiteDatabaseManager db_manager, sqlite3 *db);
};

#endif