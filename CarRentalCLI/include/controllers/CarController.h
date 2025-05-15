#pragma once
#include <string>
#include <vector>
#include <optional>

#include "models/CarModel.h"

/**
 * @brief Modifies and reads the Car table
 */
class CarController
{
public:
    bool AddCar(
        const std::string &regNo, const std::string &brand,
        const std::string &model);

    bool EditCar(
        int id, const std::string &regNo, const std::string &brand,
        const std::string &model);

    bool RemoveCar(int id);

    int CountCars();

    std::optional<CarModel> GetCarById(int carID);

    std::vector<CarModel> SearchCar(
        const std::string &searchPhrase, int field,
        const std::string &startDate = "",
        const std::string &endDate   = "");
};
