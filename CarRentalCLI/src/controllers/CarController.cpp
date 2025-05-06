#include "controllers/CarController.h"
#include <iostream>
#include "models/CarModel.h"
#include "storage.h"

void CarController::addCar(const std::string& regNo, const std::string& brand, const std::string& model)
{
    CarModel newCar {-1, regNo, brand, model};

    newCar.carID = storage.insert(newCar);
    std::cout << __FILE__ << "Car inserted successfully" << std::endl;
}

void CarController::editCar(int carID, const std::string& regNo, const std::string& brand, const std::string& model)
{
    auto car = storage.get<CarModel>(carID);

    car.regNo = regNo;
    car.brand = brand;
    car.model = model;

    storage.update(car);
    std::cout << "Storage updated successfully" << std::endl;
}

void CarController::removeCar(int carID)
{
    auto car = storage.get<CarModel>(carID);

    //TODO Du får steke litt med den error handlingen

    storage.remove<CarModel>(carID);
    std::cout << "Storage updated successfully" << std::endl;
}

int CarController::countCars()
{
    auto carCount = storage.count<CarModel>();
    return carCount;
}