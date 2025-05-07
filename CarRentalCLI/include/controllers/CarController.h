#pragma once
#include <string>
#include <bits/stl_vector.h>

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

    std::vector<CarModel> searchCar(const std::string &searchPhrase, int field);
};