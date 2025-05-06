#include "CarController.h"
#include <iostream>
#include "CarModel.h"
#include "storage.h"

#pragma region Forklaring på algoritmen
// Dette er en lang forklaring
// som forklarer hvorfor denne algoritmen
// fungerer og hva som skjer i hvert steg.
// Den kan foldes sammen i CLion.
#pragma endregion

void CarController::addCar(std::string regNo, std::string brand, std::string model)
{
    CarModel newCar {-1, regNo, brand, model};

    if (newCar.id = storage.insert(newCar))
        std::cout << "Storage updated successfully" << std::endl;
}

void CarController::editCar(int id, std::string regNo, std::string brand, std::string model)
{
    auto car = storage.get<Car>(id);

    car.regNo = regNo;
    car.brand = brand;
    car.model = model;

    if (storage.update(car))
        std::cout << "Storage updated successfully" << std::endl;
}

void CarController::removeCar(int id)
{
    auto car = storage.get<Car>(id);

    if (storage.remove(car))
        std::cout << "Storage updated successfully" << std::endl;
}