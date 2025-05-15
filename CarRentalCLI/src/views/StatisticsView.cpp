#include "views/StatisticsView.h"

#include <iostream>

#include "Utils.h"

StatisticsView::StatisticsView()
{
}

void StatisticsView::Run()
{

    std::cout << R"MENU(
==================================
            Statistics
==================================)MENU";

    std::cout << std::endl << "Customer count: " << customerController.CountCustomers() << std::endl;
    std::cout << "Car count: " << carController.CountCars() << std::endl;
    std::cout << "Active rentals: " << rentalController.CountActiveRentals() << std::endl;
    std::cout << "Completed rentals: " << rentalController.CountCompletedRentals() << std::endl;
    std::cout << "==================================" << std::endl;
}
