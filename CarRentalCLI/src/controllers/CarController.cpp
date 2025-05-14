#include "controllers/CarController.h"
#include <iostream>
#include <unordered_set>

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

bool CarController::editCar(int carID, const std::string& newRegNo, const std::string& newBrand, const std::string& newModel)
{
    auto car = storage.get<CarModel>(carID);

    car.regNo = newRegNo;
    car.brand = newBrand;
    car.model = newModel;

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

std::vector<CarModel> CarController::searchCar(const std::string& searchPhrase, int field,
                                               const std::string& startDate, const std::string& endDate)
{
    std::string likePhrase = "%" + searchPhrase + "%";
    std::vector<CarModel> allMatchingCars;

    switch (field)
    {
        case 0:
            allMatchingCars = storage.get_all<CarModel>(
                where(like(&CarModel::regNo, likePhrase)));
        break;
        case 1:
            allMatchingCars = storage.get_all<CarModel>(
                where(like(&CarModel::brand, likePhrase)));
        break;
        case 2:
            allMatchingCars = storage.get_all<CarModel>(
                where(like(&CarModel::model, likePhrase)));
        break;
        default:
            std::cerr << "Invalid field\n";
        return {};
    }

    if (startDate.empty() || endDate.empty())
        return allMatchingCars;

    // Rentals that are within the time frame
    auto conflictingRentals = storage.get_all<RentalModel>(
        where(c(&RentalModel::startDate) <= endDate &&
              c(&RentalModel::endDate) >= startDate));

    // IDs of unavailable cars
    std::unordered_set<int> unavailableCarIDs;
    for (const auto& rental : conflictingRentals)
        unavailableCarIDs.insert(rental.carID);

    // Remove unavailable
    std::vector<CarModel> availableCars;
    for (const auto& car : allMatchingCars)
    {
        if (unavailableCarIDs.find(car.carID) == unavailableCarIDs.end())
            availableCars.push_back(car);
    }

    return availableCars;
}



