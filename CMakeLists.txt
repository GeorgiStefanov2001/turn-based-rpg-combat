cmake_minimum_required(VERSION 3.24.2)
project(turn-based-rpg-combat-tests)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

# Executable for the project
set(
  SOURCES 
  src/main.cpp 
  src/character/character.cpp 
  src/fight/attack/attack.cpp
  src/character/melee/knight.cpp
  src/character/mage/sorcerer.cpp
  src/character/others/cleric.cpp
  src/user/user.cpp
  src/exceptions/custom_exception.cpp
  src/exceptions/database_exception.cpp
  src/exceptions/user_exception.cpp
  src/exceptions/attack_exception.cpp
  src/exceptions/character_exception.cpp
  src/exceptions/program_exit_exception.cpp
  src/services/user_service.cpp
  src/services/attack_service.cpp
  src/services/character_service.cpp
  src/services/knight_service.cpp
  src/services/sorcerer_service.cpp
  src/services/cleric_service.cpp
  src/controllers/user_controller.cpp
  src/controllers/character_controller.cpp
  src/controllers/attack_controller.cpp
  src/database_manager/sqlite_database_manager.cpp
  src/menus/startup_menu.cpp
  src/menus/logged_in_menu.cpp
  )

add_executable(
  project_exec
  ${SOURCES}
)

set(INCLUDE_DIRS src/)
target_include_directories(
  project_exec
  PRIVATE
  ${INCLUDE_DIRS}
)

find_package (SQLite3)

include_directories(${SQLite3_INCLUDE_DIRS})
target_link_libraries (project_exec ${SQLite3_LIBRARIES})

