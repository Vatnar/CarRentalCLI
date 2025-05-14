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
    bool addCar(const std::string& regNo, const std::string& brand, const std::string& model);
    bool editCar(int id, const std::string& regNo, const std::string& brand, const std::string& model);
    bool removeCar(int id);

    int countCars();

    std::optional<CarModel> getCarByID(int carID);
    std::vector<CarModel> searchCar(const std::string &searchPhrase, int field, const std::string &startDate = "",
        const std::string &endDate = "");

    bool ExportCarsToCSV(const std::string& filename);
};