#include "views/RentalView.h"

#include <chrono>
#include <iostream>
#include <regex>

#include "Utils.h"
#include "views/CustomerView.h"


RentalView::RentalView(const CustomerView &customerView, const CarView &carView)
{
    this->customerView = customerView;
    this->carView = carView;
}

void RentalView::Run()
{
    while (true)
    {
        std::cout << rentalMenu;
        switch (Input::getInt(1, 5))
        {
            case 1:
                addRental(); break;
            case 2:
                editRental(); break;
            case 3:
                removeRental(); break;
            case 4:
                listRentals(); break;
            default: return;
        }
    }
}

int RentalView::getCustomerID()
{
     return customerView.getCustomerID();
}
int RentalView::getCarID(const std::string& startDate, const std::string& endDate)
{

    std::string searchString;
    int field = 0;
    std::cout << "Press 0, 1, or 2 to select search field\n0: RegNo\n1: Brand\n2: Model\n:";
    field = Input::getInt(0, 2);

    std::cout << "\nInput search string. Press Enter to search. Press enter without search string to list all\n ";
    searchString = Input::getString();
    std::cout << searchString << std::endl;

    std::vector<CarModel> cars = carController.searchCar(searchString, field, startDate, endDate);
    if (cars.empty())
    {
        std::cout << "\n Car not found. Try again";
        return getCarID(startDate, endDate);
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


bool RentalView::matchesPattern(const std::string& s) {
    // Matches format YYYY-MM-DD hh-mm
    std::regex pattern(R"(\d{4}-\d{2}-\d{2} \d{2}-\d{2})");
    return std::regex_match(s, pattern);
}


std::string RentalView::getStartdate()
{
    std::cout << "Enter start date [YYYY-MM-DD hh-mm]\n Click enter without entering anything to choose current time:\n ";
    std::string startDate = Input::getString();
    if (startDate.empty())
    {
        std::cout << "Using current date/time: " << startDate << "\n";
        return Time::getCurrentTime();
    }
    if (!matchesPattern(startDate))
    {
        std::cout << "Invalid date, Try again\n ";
        return getEndDate();
    }
    return startDate;
}
std::string RentalView::getEndDate()
{
    std::cout << "Enter end date [YYYY-MM-DD hh-mm] : ";
    std::string endDate = Input::getString();
    if (endDate.empty() || !matchesPattern(endDate))
    {
        std::cout << "Invalid date, Try again\n ";
        return getEndDate();
    }
    return endDate;
}
int RentalView::getRentalID()
{
    int field = 0;
    std::cout << "Press 0, 1, 2, or 3 to select search field\n 0: Customer \n 1: Car\n 2: Start Date\n 3: End Date\n 4: All rentals\n:";
    field = Input::getInt(0, 4);
    std::vector<RentalModel> rentals;
    switch (field)
    {
        case 0:
        {
            int customerID = getCustomerID();
            rentals = rentalController.Search("", 0, customerID);
            break;
        }
        case 1:
        {
            int carID = carView.getCarID();
            rentals = rentalController.Search("", 1, carID);
            break;
        }
        case 2:
        {
            std::string startDate = getStartdate();
            rentals = rentalController.Search("startDate", 2);
            break;
        }
        case 3:
        {
            std::string endDate = getEndDate();
            rentals = rentalController.Search("endDate", 3);
            break;
        }
        case 4:
            {rentals = rentalController.Search("", 4);}
    }
    if (rentals.empty())
    {
        std::cout << "\n Rental not found. Try again";
        return getRentalID();
    }


    std::cout << "Found " << rentals.size() << " out of " << rentalController.CountRentals() << std::endl;
    int index = 0;
    for (const auto& rental : rentals)
    {
        std::cout << index++ << ".\t "  << rental.rentalID << "\t" << rental.customerID << "\t\t" << rental.carID << "\t\t" << rental.dateRented << "\t\t" << rental.dateReturned << std::endl;
    }
    std::cout << "Enter number to choose: ";
    auto indexCustomer = Input::getInt(0, rentals.size()-1); // -1 cuz of 0 index
    return rentals[indexCustomer].rentalID;
}


void RentalView::addRental()
{
    std::cout << R"MENU(
==================================
            Add Rental
==================================
)MENU" << std::endl;
    std::string reg, brand, model;

    std::string startdate = getStartdate();
    std::string endDate = getEndDate();

    std::cout << "Choose customer" << std::endl;
    int customerID = getCustomerID();

    std::cout << "Choose car" << std::endl;
    int carID = getCarID(startdate, endDate);

    rentalController.rentCar(customerID, carID,startdate, endDate);
}
void RentalView::editRental()
{
    std::cout << R"MENU(
==================================
            Edit Rental
==================================
    )MENU" << std::endl;


    int rentalID = getRentalID();
     const auto rental = rentalController.getRentalByID(rentalID);
    if ( rental == std::nullopt)
    {
        std::cout << "INTERNAL FAILURE " << __FILE__ << __LINE__ << std::endl;
    }
    std::cout << rental->rentalID << "\t" << rental->customerID << "\t\t" << rental->carID << "\t\t" << rental->dateRented << "\t\t" << rental->dateReturned << std::endl;


    std::cout << "Choose customer" << std::endl;
    int customerID = getCustomerID();

    std::cout << "Choose car" << std::endl;
    int carID = carView.getCarID();
    std::string startDate = getStartdate();
    std::string endDate = getEndDate();

    rentalController.EditRental(rentalID, startDate, endDate, customerID, carID);
}
void RentalView::removeRental()
{
    std::cout << R"MENU(
==================================
            Remove Rental
==================================
    )MENU" << std::endl;

    int rentalID = getRentalID();


    rentalController.RemoveRental(rentalID);
}

void RentalView::listRentals() {
    std::vector<RentalModel> rentals = rentalController.Search("", 3);
    if (rentals.empty())
    {
        std::cout << " No rentals in system\n";
        return;
    }
    std::cout << rentals.size() << " Rentals" << std::endl;
    int index = 0;
    for (const auto& rental : rentals)
    {
        std::cout << index++ << ".\t "  << rental.rentalID << "\t" << rental.customerID << "\t\t" << rental.carID << "\t\t" << rental.dateRented << "\t\t" << rental.dateReturned << std::endl;
    }
}
