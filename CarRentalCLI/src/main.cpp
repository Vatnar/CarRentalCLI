#include <iostream>
#include <sqlite3.h>
#include "storage.h"
#include "controllers/CarController.h"
#include "controllers/CustomerController.h"
#include "views/MainView.h"
#include <filesystem>
void addSampleData()
{

    // TODO Add sample data to rental controller

    std::filesystem::remove("CarRental.sqlite");

    storage.sync_schema();
    CustomerController customerController;
    CarController carController;
    RentalController rentalController;


    customerController.addCustomer("Name1", "Tel1", "email1@example.com");
    customerController.addCustomer("Name2", "Tel2", "email2@example.com");
    customerController.addCustomer("Name3", "Tel3", "email3@example.com");

    carController.addCar("AA00000", "Brand1", "Model1");
    carController.addCar("AA00001", "Brand2", "Model2");
    carController.addCar("AA00002", "Brand3", "Model3");

    // rentalController.addRental();

    std::cout << "Adding sample data" << std::endl;

    // TODO Verify that it adds stuff
}
int main()
{

    // TODO run checks for integrity, check dates and return cars
    addSampleData();
    MainView menu;
    menu.Run();

    return 0;
}

