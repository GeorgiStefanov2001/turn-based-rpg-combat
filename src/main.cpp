#include <character/melee/knight.h>

#include <menus/startup_menu.h>
#include <menus/logged_in_menu.h>
#include <user/user.h>
#include <database_manager/sqlite_database_manager.h>
#include <controllers/user_controller.h>
#include <exceptions/database_exception.h>
#include <exceptions/user_exception.h>
#include <exceptions/program_exit_exception.h>

#include <sqlite3.h>

#include <map>
#include <string>
#include <iostream>

const char *DB_DIR_NAME = "database/turn-based-rpg-combat";

int main()
{
    SQLiteDatabaseManager db_manager;
    sqlite3 *db = db_manager.connect_to_database(DB_DIR_NAME);
    User user;
    StartupMenu startup_menu;
    LoggedInMenu logged_in_menu;
    bool logged_in = false;

    try
    {
        db_manager.create_tables(db);

        /**
         * For dev purposes, create admin user so we can test stuff
         * for creds, check the method implementation
         */
        db_manager.create_admin_user(db);

        while (true)
        {
            startup_menu.display(logged_in, user, db_manager, db);
            logged_in_menu.display(logged_in, user, db_manager, db);
        }

        db_manager.close_database_connection(db);
    }
    catch (DatabaseException e)
    {
        std::cerr << "DB ERROR: " << e.what() << std::endl;
        db_manager.close_database_connection(db);
    }
    catch (ProgramExitException e)
    {
        std::cout << e.what() << std::endl;
        db_manager.close_database_connection(db);
    }

    return 0;
}