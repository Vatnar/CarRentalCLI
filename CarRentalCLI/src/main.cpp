#include <iostream>
#include <sqlite3.h>
#include "storage.h"
#include "controllers/CarController.h"
#include "controllers/CustomerController.h"
#include "views/MainView.h"

int main()
{
    MainView menu;

    // std::cout << "Hello, World!" << std::endl;
    return 0;
}

void addSampleData()
{
    CustomerController::addCustomer("Alice Johnson", "555-1234", "alice@example.com");
    CustomerController::addCustomer("Bob Smith", "555-5678", "bob.smith@example.com");
    CustomerController::addCustomer("Charlie Brown", "555-9012", "charlie@brownmail.com");

    CarController::addCar("AB12345", "Toyota", "Corolla");
    CarController::addCar("CD67890", "Ford", "Mustang");
    CarController::addCar("EF11223", "Tesla", "Model 3");

}