#include <iostream>
#include <sqlite3.h>
#include "storage.h"
#include "controllers/CarController.h"
#include "controllers/CustomerController.h"
#include "views/MainView.h"
#include <filesystem>

int main()
{
    MainView menu;

    return 0;
}

void addSampleData()
{

    // TODO Add sample data to rental controller

    std::filesystem::remove("CarRental.sqlite");

    storage.sync_schema();
    CustomerController customerController;
    CarController carController;
    // customerController.addCustomer("name1", "tel1", "email1");
    // customerController.addCustomer("name2", "tel2", "email2");
    // customerController.addCustomer("nam3", "tel3", "email3");

    carController.addCar("Reg1", "Brand1", "Model1");
    carController.addCar("Reg2", "Brand2", "Model2");
    carController.addCar("Reg3", "Brand3", "Model3");

    std::cout << "Adding sample data" << std::endl;

    // TODO Verify that it adds stuff
}