#include "controllers/CarController.h"
#include <iostream>
#include "models/CarModel.h"
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

    if ((newCar.carID = storage.insert(newCar)))
        std::cout << __FILE__ << "Car inserted successfully" << std::endl;
}

void CarController::editCar(int id, std::string regNo, std::string brand, std::string model)
{
    auto car = storage.get<CarModel>(id);

    car.regNo = regNo;
    car.brand = brand;
    car.model = model;

    // TODO needs to be fixed
    // if (storage.update(car))
        // std::cout << "Storage updated successfully" << std::endl;
}

void CarController::removeCar(int id)
{
    auto car = storage.get<CarModel>(id);


    // TODO needs fix
    // if (storage.remove(car))
        // std::cout << "Storage updated successfully" << std::endl;
}

void CarController::countCars(int id)
{
    auto carCount = storage.select(count(id));
    //if (storage.remove(car))
      //  std::cout << "Storage updated successfully" << std::endl;
}