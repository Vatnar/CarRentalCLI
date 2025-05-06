#include "controllers/CarController.h"
#include <iostream>
#include "models/CarModel.h"
#include "storage.h"

void CarController::addCar(std::string regNo, std::string brand, std::string model)
{
    CarModel newCar {-1, regNo, brand, model};

    if ((newCar.carID = storage.insert(newCar)))
        std::cout << __FILE__ << "Car inserted successfully" << std::endl;
}

void CarController::editCar(int id, std::string regNo, std::string brand, std::string model)
{
    auto car = storage.get<CarModel>(id);

    car.regNo = regNo;
    car.brand = brand;
    car.model = model;

    storage.update(car);
    std::cout << "Storage updated successfully" << std::endl;
}

void CarController::removeCar(int id)
{
    auto car = storage.get<CarModel>(id);

    //TODO Du får steke litt med den error handlingen

    storage.remove<CarModel>(id);
    std::cout << "Storage updated successfully" << std::endl;
}

int CarController::countCars()
{
    auto carCount = storage.count<CarModel>();
    return carCount;
}