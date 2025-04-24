cmake_minimum_required(VERSION 3.30)
project(CarRentalGUI)

set(CMAKE_CXX_STANDARD 20)
add_library(sqlite3 STATIC vendor/sqlite3/sqlite3.c)
target_include_directories(sqlite3 PUBLIC vendor/sqlite3)

include_directories(vendor/sqlite_orm)
add_executable(CarRentalGUI src/main.cpp
        include/storage.h
        src/views/MainView.cpp
        include/views/MainView.h
        include/Utils.h
        src/views/CustomerView.cpp
        include/views/CustomerView.h
        src/CustomerModel.cpp
        include/CustomerModel.h
        src/CarModel.cpp
        include/CarModel.h
        src/views/CarView.cpp
        include/views/CarView.h
        src/views/RentalView.cpp
        include/views/RentalView.h
        src/views/StatisticsView.cpp
        include/views/StatisticsView.h
        src/views/ImportExportView.cpp
        include/views/ImportExportView.h)


target_include_directories(CarRentalGUI PRIVATE include)
target_link_libraries(CarRentalGUI PRIVATE sqlite3)
