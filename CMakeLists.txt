cmake_minimum_required(VERSION 3.24.2)
project(turn-based-rpg-combat-tests)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

# Executable for the project
set(SOURCES src/main.cpp src/character/character.cpp)
add_executable(
  project_exec
  ${SOURCES}
)

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

include(GoogleTest)
gtest_discover_tests(project_tests)

