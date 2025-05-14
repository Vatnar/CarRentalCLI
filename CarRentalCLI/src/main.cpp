#include <filesystem>
#include <iostream>
#include <sqlite3.h>

#include "storage.h"
#include "controllers/CarController.h"
#include "controllers/CustomerController.h"
#include "views/MainView.h"

void addSampleData()
{
    std::filesystem::remove("CarRental.sqlite");

    storage.sync_schema();
    CustomerController customerController;
    CarController carController;
    RentalController rentalController;


    customerController.addCustomer("Name1", "Tel1", "email1@example.com");
    customerController.addCustomer("Name2", "Tel2", "email2@example.com");
    customerController.addCustomer("Name3", "Tel3", "email3@example.com");
    customerController.addCustomer("Name4", "Tel4", "email4@example.com");
    customerController.addCustomer("Name5", "Tel5", "email5@example.com");
    customerController.addCustomer("Name6", "Tel6", "email6@example.com");
    customerController.addCustomer("Name7", "Tel7", "email7@example.com");
    customerController.addCustomer("Name8", "Tel8", "email8@example.com");


    carController.addCar("AA00000", "Brand1", "Model1");
    carController.addCar("AA00001", "Brand1", "Model2");
    carController.addCar("AA00002", "Brand3", "Model3");
    carController.addCar("AA00003", "Brand1", "Model4");
    carController.addCar("AA00004", "Brand2", "Model2");
    carController.addCar("AA00005", "Brand3", "Model2");
    carController.addCar("AA00006", "Brand1", "Model3");
    carController.addCar("AA00007", "Brand1", "Model2");
    carController.addCar("AA00008", "Brand2", "Model3");

    rentalController.rentCar(1, 3, "2024-01-10", "2024-01-15");
    rentalController.rentCar(2, 1, "2024-02-01", "2024-02-05");
    rentalController.rentCar(3, 5, "2024-03-12", "2024-03-20");
    rentalController.rentCar(4, 4, "2024-04-01", "2024-04-10");
    rentalController.rentCar(5, 2, "2024-05-05", "2024-05-12");
    rentalController.rentCar(6, 6, "2024-06-20", "2024-06-30");
    rentalController.rentCar(7, 7, "2025-04-01", "2025-07-15");
    rentalController.rentCar(8, 8, "2025-04-10", "2025-08-18");
    rentalController.rentCar(2, 9, "2025-05-01", "2025-09-07");
    rentalController.rentCar(1, 1, "2025-15-01", "2025-10-05");



    std::cout << "Adding sample data" << std::endl;

}
int main()
{

    addSampleData();
    MainView menu;
    menu.Run();

    return 0;
}

