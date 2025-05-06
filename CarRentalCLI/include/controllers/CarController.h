#pragma once
#include <string>

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

    void searchCar();
};