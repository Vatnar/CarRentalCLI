#include "controllers/CarController.h"
#include "storage.h"
#include <fstream>
#include <iostream>
#include <unordered_set>
#include <rapidcsv.h>


/**
 * @brief Adds a new car to the storage.
 *
 * This function creates a new car with the provided details and inserts it into the storage.
 * The car will be assigned a unique carID upon successful insertion.
 *
 * @param regNo The registration number of the car.
 * @param brand The brand of the car.
 * @param model The model of the car.
 * @return true if the car was added successfully, false if an error occurred.
 */
bool CarController::AddCar(
    const std::string &regNo, const std::string &brand,
    const std::string &model)
{
    CarModel newCar{-1, regNo, brand, model};

    try
    {
        newCar.carID = storage.insert(newCar);
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}


/**
 * @brief Edits an existing car's details.
 *
 * This function updates the details of an existing car with the provided new information.
 * The car is identified by its carID, and its registration number, brand, and model are updated.
 *
 * @param carID The ID of the car to be edited.
 * @param newRegNo The new registration number for the car.
 * @param newBrand The new brand for the car.
 * @param newModel The new model for the car.
 * @return true if the car was successfully updated, false if an error occurred.
 */
bool CarController::EditCar(
    int carID, const std::string &newRegNo, const std::string &newBrand,
    const std::string &newModel)
{
    auto car = storage.get<CarModel>(carID);

    car.regNo = newRegNo;
    car.brand = newBrand;
    car.model = newModel;

    try
    {
        storage.update(car);
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}


/**
 * @brief Removes a car from the storage.
 *
 * This function deletes a car from the storage using the car's unique carID.
 *
 * @param carID The ID of the car to be removed.
 * @return true if the car was successfully removed, false if an error occurred.
 */
bool CarController::RemoveCar(int carID)
{
    try
    {
        storage.remove<CarModel>(carID);
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}


/**
 * @brief Counts the total number of cars in the storage.
 *
 * This function returns the total count of cars currently stored.
 *
 * @return The total number of cars in the storage.
 */
int CarController::CountCars()
{
    auto carCount = storage.count<CarModel>();
    return carCount;
}


/**
 * @brief Searches for cars based on various fields.
 *
 * This function allows searching for cars by registration number, brand, or model.
 * Optionally, it can also filter the cars based on a date range for rental availability.
 *
 * @param searchPhrase The phrase to search for in the chosen field.
 * @param field The field to search in (0 for regNo, 1 for brand, 2 for model).
 * @param startDate The start date of the rental period (optional).
 * @param endDate The end date of the rental period (optional).
 * @return A vector of cars matching the search criteria, including availability based on the rental dates.
 */
std::vector<CarModel> CarController::SearchCar(
    const std::string &searchPhrase, int             field,
    const std::string &startDate, const std::string &endDate)
{
    std::string           likePhrase = "%" + searchPhrase + "%";
    std::vector<CarModel> allMatchingCars;

    switch (field)
    {
        case 0: allMatchingCars = storage.get_all<CarModel>(
                    where(like(&CarModel::regNo, likePhrase)));
            break;
        case 1: allMatchingCars = storage.get_all<CarModel>(
                    where(like(&CarModel::brand, likePhrase)));
            break;
        case 2: allMatchingCars = storage.get_all<CarModel>(
                    where(like(&CarModel::model, likePhrase)));
            break;
        default: std::cerr << "Invalid field\n";
            return {};
    }

    if (startDate.empty() || endDate.empty()) return allMatchingCars;

    // Rentals that are within the time frame
    auto conflictingRentals = storage.get_all<RentalModel>(
        where(
            c(&RentalModel::startDate) <= endDate &&
            c(&RentalModel::endDate) >= startDate));

    // IDs of unavailable cars
    std::unordered_set<int> unavailableCarIDs;
    for (const auto &rental: conflictingRentals) unavailableCarIDs.insert(
        rental.carID);

    // Remove unavailable
    std::vector<CarModel> availableCars;
    for (const auto &car: allMatchingCars)
    {
        if (unavailableCarIDs.find(car.carID) == unavailableCarIDs.
            end()) availableCars.push_back(car);
    }

    return availableCars;
}


/**
 * @brief Retrieves a car by its ID.
 *
 * @param carID The ID of the car to retrieve.
 * @return The CarModel if found, or std::nullopt if not found.
 */
std::optional<CarModel> CarController::GetCarById(int id)
{
    try
    {
        auto car = storage.get<CarModel>(id);
        return car;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error in GetCarById: " << e.what() << std::endl;
        return std::nullopt;
    }
}
