cmake_minimum_required(VERSION 3.30)
project(CarRentalGUI)

set(CMAKE_CXX_STANDARD 20)
add_library(sqlite3 STATIC vendor/sqlite3/sqlite3.c)
target_include_directories(sqlite3 PUBLIC vendor/sqlite3)

include_directories(vendor/sqlite_orm)
add_executable(CarRentalGUI src/main.cpp
        include/storage.h
        src/Customer.cpp
        include/Customer.h
        src/Car.cpp
        include/Car.h
        src/Menu.cpp
        include/Menu.h)

target_include_directories(CarRentalGUI PRIVATE include)
target_link_libraries(CarRentalGUI PRIVATE sqlite3)
