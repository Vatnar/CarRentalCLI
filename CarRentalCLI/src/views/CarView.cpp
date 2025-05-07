#include "views/CarView.h"

#include <iostream>
#include <vector>

#include "Utils.h"
#include "models/CarModel.h"

CarView::CarView()
{
    std::cout << carMenu;
    switch (Input::getInt(1, 4))
    {
        case 1:
            addCar(); break;
        case 2:
            editCar(); break;
        case 3:
            removeCar(); break;
        case 4:
            return;
    }
    CarView cw;
}

bool CarView::isValid(const std::string& s) {
    return s.length() == 7 &&
           std::isalpha(s[0]) &&
           std::isalpha(s[1]) &&
           std::isdigit(s[2]) &&
           std::isdigit(s[3]) &&
           std::isdigit(s[4]) &&
           std::isdigit(s[5]) &&
           std::isdigit(s[6]);
}

void CarView::getReg(std::string &reg)
{
    std::cout << "Enter the registration number";
    reg = Input::getString(false);

    if (reg.empty() || !isValid(reg))
    {
        std::cout << "Invalid brand, Try again (LJ12345): ";
        getBrand(reg);
    }
}
void CarView::getBrand(std::string &brand)
{
    std::cout << "Enter the brand name: ";
    brand = Input::getString();
    if (brand.empty())
    {
        std::cout << "Invalid brand, Try again: ";
        getBrand(brand);
    }
}
void CarView::getModel(std::string &model)
{
    std::cout << "Enter the model name: ";
    model = Input::getString();
    if (model.empty())
    {
        std::cout << "Invalid model, Try again: ";
        getBrand(model);
    }
}


void CarView::addCar() {}
void CarView::editCar() {}
void CarView::removeCar() {}

int CarView::getCarID()
{
    std::string searchString;
    int field = 0;
    std::cout << "0: RegNo. 1: Brand. 2: Model: ";
    field = Input::getInt(0, 2);

    std::cout << "\nInput search string. Press Enter to search. Press enter without search string to list all\n ";
    searchString = Input::getString();
    std::cout << searchString << std::endl;

    std::vector<CarModel> cars = carController.searchCar(searchString, field);
    if (cars.empty())
    {
        std::cout << "\n Car not found. Try again";
        getCarID();
    }
    std::cout << "Found " << cars.size() << " out of " << carController.countCars() << std::endl;
    int index = 0;
    for (const auto& car : cars)
    {
        std::cout << index++ << ".\t " << car.regNo << "\t\t" << car.brand << "\t\t" << car.model << std::endl;
    }
    std::cout << "Enter number to choose: ";
    auto indexCustomer = Input::getInt(0, cars.size()-1); // -1 cuz of 0 index
    return cars[indexCustomer].carID;
}

