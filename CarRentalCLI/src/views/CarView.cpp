#include "views/CarView.h"

#include <iostream>
#include <vector>

#include "Utils.h"
#include "models/CarModel.h"

CarView::CarView() = default;

void CarView::Run()
{
    while (true)
    {
        std::cout << carMenu;
        switch (Input::GetInt(1, 5))
        {
            case 1:
                addCar(); break;
            case 2:
                editCar(); break;
            case 3:
                removeCar(); break;
            case 4:
                listCars();
            default:
                return;
        }
    }
}

bool CarView::isValidReg(const std::string& s) {
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
    reg = Input::GetString(false);

    if (reg.empty() || !isValidReg(reg))
    {
        std::cout << "Invalid brand, Try again (LJ12345): ";
        getBrand(reg);
    }
}
void CarView::getBrand(std::string &brand)
{
    std::cout << "Enter the brand name: ";
    brand = Input::GetString();
    if (brand.empty())
    {
        std::cout << "Invalid brand, Try again: ";
        getBrand(brand);
    }
}
void CarView::getModel(std::string &model)
{
    std::cout << "Enter the model name: ";
    model = Input::GetString();
    if (model.empty())
    {
        std::cout << "Invalid model, Try again: ";
        getBrand(model);
    }
}


void CarView::addCar()
{
    std::cout << R"MENU(
==================================
            Add Car
==================================
)MENU" << std::endl;
    std::string reg, brand, model;
    getReg(reg);
    getBrand(brand);
    getModel(model);

    carController.AddCar(reg, brand, model);
}
void CarView::editCar()
{
    std::cout << R"MENU(
==================================
            Edit Car
==================================
    )MENU" << std::endl;

    int carID = getCarID();
    std::string reg, brand, model;

    const auto car = carController.GetCarById(carID);
    if ( car == std::nullopt)
    {
        std::cout << "INTERNAL FAILURE " << __FILE__ << __LINE__ << std::endl;
    }
    std::cout << car->regNo << "\t\t" << car->brand << "\t\t" << car->model << std::endl;
    getReg(reg);
    getBrand(brand);
    getModel(model);

    carController.EditCar(carID, reg, brand, model);
}
void CarView::removeCar()
{
    std::cout << R"MENU(
==================================
            Remove Car
==================================
    )MENU" << std::endl;

    int carID = getCarID();

    carController.RemoveCar(carID);
}

void CarView::listCars()
{
    std::vector<CarModel> cars = carController.SearchCar("", 1);
    if (cars.empty())
    {
        std::cout << " No cars in system\n";
        return;
    }
    std::cout << cars.size() << " Cars" << std::endl;
    int index = 0;
    for (const auto& car : cars)
    {
        std::cout << index++ << ".\t " << car.regNo << "\t\t" << car.brand << "\t\t" << car.model << std::endl;
    }
}

int CarView::getCarID()
{
    std::string searchString;
    int field = 0;
    std::cout << "Press 0, 1, or 2 to select search field\n0: RegNo\n1: Brand\n2: Model\n:";
    field = Input::GetInt(0, 2);

    std::cout << "\nInput search string. Press Enter to search. Press enter without search string to list all\n ";
    searchString = Input::GetString();
    std::cout << searchString << std::endl;

    std::vector<CarModel> cars = carController.SearchCar(searchString, field);
    if (cars.empty())
    {
        std::cout << "\n Car not found. Try again";
        return getCarID();
    }
    std::cout << "Found " << cars.size() << " out of " << carController.CountCars() << std::endl;
    int index = 0;
    for (const auto& car : cars)
    {
        std::cout << index++ << ".\t " << car.regNo << "\t\t" << car.brand << "\t\t" << car.model << std::endl;
    }
    std::cout << "Enter number to choose: ";
    auto indexCustomer = Input::GetInt(0, cars.size()-1); // -1 cuz of 0 index
    return cars[indexCustomer].carID;
}

