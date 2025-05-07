#include "views/RentalView.h"

#include <chrono>
#include <iostream>
#include <regex>

#include "Utils.h"
#include "views/CustomerView.h"

class RentalModel;

RentalView::RentalView() {
    std::cout << rentalMenu;
    switch (Input::getInt(1, 4))
    {
        case 1:
            addRental(); break;
        case 2:
            editRental(); break;
        case 3:
            removeRental(); break;
        case 4:
            return;
    }
    RentalView rw;
}

int RentalView::getCustomerID()
{
    // TODO Reuse CarVIEW::getCarID() but move it out of carview
    std::string searchString;
    std::cout << "Input search string. Press Enter to search. Press enter without search string to list all\n ";
    searchString = Input::getString();
    std::cout << searchString << std::endl;

    std::vector<CustomerModel> customers = customerController.searchCustomer(searchString);
    if (customers.empty())
    {
        std::cout << "\n Customer not found. Try again" << std::endl;
        getCustomerID();
    }
    std::cout << "Found " << customers.size() << " out of " << customerController.countCustomers() << std::endl;
    int index = 0;
    for (const auto& customer : customers)
    {
        std::cout << index++ << ".\t " << customer.name << "\t\t" << customer.tel << "\t\t" << customer.email << std::endl;
    }
    std::cout << "Enter number to choose: ";
    auto indexCustomer = Input::getInt(0, customers.size()-1); // -1 cuz of 0 index
    return customers[indexCustomer].customerID;

}
int RentalView::getCarID(const std::string& startDate, const std::string& endDate)
{
    // TODO Reuse CarVIEW::getCarID() but move it out of carview
    // TODO only list cars that are available
    std::string searchString;
    int field = 0;
    std::cout << "Press 0, 1, or 2 to select search field\n0: RegNo\n1: Brand\n2: Model\n:";
    field = Input::getInt(0, 2);

    std::cout << "\nInput search string. Press Enter to search. Press enter without search string to list all\n ";
    searchString = Input::getString();
    std::cout << searchString << std::endl;

    std::vector<CarModel> cars = carController.searchCar(searchString, field);
    if (cars.empty())
    {
        std::cout << "\n Car not found. Try again";
        getCarID(startDate, endDate);
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
std::string RentalView::getCurrentDateTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm localTime = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&localTime, "%Y-%m-%d %H-%M");
    return oss.str();
}

std::string RentalView::getStartdate()
{
    std::cout << "Enter start date [YYYY-MM-DD hh-mm]\n Click enter to choose current time:\n : ";
    std::string startDate = Input::getString();
    if (startDate.empty())
    {
        std::cout << "Using current date/time: " << startDate << "\n";
        return getCurrentDateTime();
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
    // int field = 0;
    // std::cout << "Press 0, 1, 2, or 3 to select search field\n 0: Customer \n 1: Car\n 2: Date Rented\n 3: Date Returned\n 4: All rentals\n:";
    // field = Input::getInt(0, 4);
    // std::vector<RentalModel> rentals;
    // switch (field)
    // {
    //     case 1:
    //         int customerID = getCustomerID();
    //     rentals = rentalController.search("", 0, customerID);
    //     break;
    //     case 2:
    //         // TODO fix this
    //         // int carID = getCarID();
    //             break;
    //
    // }
    return 0;
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
    int customerID = getCustomerID();
    int carID = getCarID(startdate, endDate);

    rentalController.rentCar(customerID, carID,startdate, endDate);
}
void RentalView::editRental() {}
void RentalView::removeRental() {}
