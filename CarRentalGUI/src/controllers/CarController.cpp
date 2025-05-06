#include "controllers/CarController.h"
#include <iostream>
#include "models/CarModel.h"
#include "storage.h"

void CarController::addCar(std::string regNo, std::string brand, std::string model)
{
    CarModel newCar {-1, regNo, brand, model};

    if ((newCar.carID = storage.insert(newCar)))
        std::cout << __FILE__ << "Storage updated successfully" << std::endl;
}

void CarController::editCar(int id, std::string regNo, std::string brand, std::string model)
{
    auto car = storage.get<Car>(id);

    car.regNo = regNo;
    car.brand = brand;
    car.model = model;

    if (storage.update(car))
        std::cout << "Storage updated successfully" << std::endl;
}

void CarController::removeCar(int id)
{
    auto car = storage.get<Car>(id);

    if (storage.remove(car))
        std::cout << "Storage updated successfully" << std::endl;
}

void CarController::countCars(int id)
{
    auto carCount = storage.select(count(id));
}