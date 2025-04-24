#include "CarController.h"
#include "../models/CarModel.h"

void CarController::addCar(regNo, brand, model)
{
    CarModel newCar {-1, regNo, brand, model};

    if (newCar.id = storage.insert(newCar))
        std::cout << "Storage updated successfully" << std::endl;
}

void CarController::editCar(id, regNo, brand, model)
{
    auto car = storage.get<Car>(id);

    car.regNo = regNo;
    car.brand = brand;
    car.model = model;

    if (storage.update(customer))
        std::cout << "Storage updated successfully" << std::endl;
}

void CarController::removeCar(id)
{
    auto car = storage.get<Car>(id);

    if (storage.remove(car))
        std::cout << "Storage updated successfully" << std::endl;
}

void CarController::countCars()
{
    auto carCount = storage.select(count(id));
}