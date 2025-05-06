#pragma once
#include <string>

/**
 * @brief Modifies and reads the Car table
 */
class CarController
{
public:
    void addCar(const std::string& regNo, const std::string& brand, const std::string& model);
    void editCar(int id, const std::string& regNo, const std::string& brand, const std::string& model);
    void removeCar(int id);

    int countCars();

    void searchCar();
};