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
    customerController.addCustomer("Name1", "Tel1", "email1@example.com");
    customerController.addCustomer("Name2", "Tel2", "email2@example.com");
    customerController.addCustomer("Name3", "Tel3", "email3@example.com");

    carController.addCar("Reg1", "Brand1", "Model1");
    carController.addCar("Reg2", "Brand2", "Model2");
    carController.addCar("Reg3", "Brand3", "Model3");

    std::cout << "Adding sample data" << std::endl;

    // TODO Verify that it adds stuff
}
int main()
{
    addSampleData();
    MainView menu;

    return 0;
}

