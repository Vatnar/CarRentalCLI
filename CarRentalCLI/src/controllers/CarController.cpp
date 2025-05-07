#include "controllers/CarController.h"
#include <iostream>
#include "models/CarModel.h"
#include "storage.h"

bool CarController::addCar(const std::string& regNo, const std::string& brand, const std::string& model)
{
    CarModel newCar {-1, regNo, brand, model};

    try {
        newCar.carID = storage.insert(newCar);
        return true;
    }
    catch (const std::exception& e) {
        return false;
    }
}

bool CarController::editCar(int carID, const std::string& regNo, const std::string& brand, const std::string& model)
{
    auto car = storage.get<CarModel>(carID);

    car.regNo = regNo;
    car.brand = brand;
    car.model = model;

    try {
        storage.update(car);
        return true;
    }
    catch (const std::exception& e) {
        return false;
    }
}

bool CarController::removeCar(int carID)
{
    auto car = storage.get<CarModel>(carID);

    try
    {
        storage.remove<CarModel>(carID);
        return true;
    }
    catch (const std::exception& e) {
        return false;
    }
}

int CarController::countCars()
{
    auto carCount = storage.count<CarModel>();
    return carCount;
}

std::vector<CarModel> CarController::searchCar(const std::string& searchPhrase, int field)
{
    std::string likePhrase = "%" + searchPhrase + "%";
    std::vector<CarModel> cars;

    switch (field)
    {
        case 0:
            cars = storage.get_all<CarModel>(
          where(like(&CarModel::regNo, likePhrase))); break;
        case 1:
            cars = storage.get_all<CarModel>(
          where(like(&CarModel::brand, likePhrase))); break;
        case 2:
            cars = storage.get_all<CarModel>(
          where(like(&CarModel::model, likePhrase))); break;
        default: std::cerr << "Invalid field";
    }
    return cars;
}
