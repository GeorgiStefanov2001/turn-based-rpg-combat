cmake_minimum_required(VERSION 3.24.2)
project(turn-based-rpg-combat-tests)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

# Executable for the project
set(
  SOURCES 
  src/main.cpp 
  src/character/character.cpp 
  src/character/melee/knight.cpp
  src/users/user.cpp
  src/exceptions/database_exception.cpp
  src/services/user_service.cpp
  src/controllers/user_controller.cpp
  src/database_manager/sqlite_database_manager.cpp
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


#Gtest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Executable for the tests
set(TEST_SOURCES tests/character/test_character.cpp)
add_executable(
  project_tests
  ${TEST_SOURCES}
)
target_link_libraries(
  project_tests
  GTest::gtest_main
)

set(INCLUDE_DIRS ./)
target_include_directories(
  project_tests
  PRIVATE
  ${INCLUDE_DIRS}
)

include(GoogleTest)
gtest_discover_tests(project_tests)

