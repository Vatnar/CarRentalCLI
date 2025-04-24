cmake_minimum_required(VERSION 3.30)
project(CarRentalGUI)

set(CMAKE_CXX_STANDARD 20)
add_library(sqlite3 STATIC vendor/sqlite3/sqlite3.c)

target_include_directories(sqlite3 PUBLIC vendor/sqlite3)
include_directories(vendor/sqlite_orm)

add_executable(CarRentalGUI main.cpp
        vendor/gtkmm/storage.h)

target_link_libraries(CarRentalGUI PRIVATE sqlite3)