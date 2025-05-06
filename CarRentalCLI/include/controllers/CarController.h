#pragma once
#include <string>

/**
 * @brief Modifies and reads the Car table
 */
class CarController
{
public:
    void addCar(std::string regNo, std::string brand, std::string model);
    void editCar(int id, std::string regNo, std::string brand, std::string model);
    void removeCar(int id);

    int countCars();

    void searchCar();
};