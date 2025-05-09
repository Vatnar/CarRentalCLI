cmake_minimum_required(VERSION 3.30)
project(CarRentalCLI)

set(CMAKE_CXX_STANDARD 20)
add_library(sqlite3 STATIC vendor/sqlite3/sqlite3.c)
target_include_directories(sqlite3 PUBLIC vendor/sqlite3)

include_directories(vendor/sqlite_orm)

file(GLOB_RECURSE SOURCES
        src/*.cpp
)

file(GLOB_RECURSE HEADERS
        *.h
        include/*.h
)
add_executable(CarRentalCLI ${SOURCES} ${HEADERS}
        include/views/View.h)



target_include_directories(CarRentalCLI PRIVATE include)
target_link_libraries(CarRentalCLI PRIVATE sqlite3)
