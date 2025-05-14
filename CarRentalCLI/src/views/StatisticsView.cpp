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

    std::cout << std::endl << "Customer count: " << customerController.countCustomers() << std::endl;
    std::cout << "Car count: " << carController.countCars() << std::endl;
    std::cout << "Active rentals: " << rentalController.countActiveRentals() << std::endl;
    std::cout << "Completed rentals: " << rentalController.countCompletedRentals() << std::endl;
    std::cout << "==================================" << std::endl;
}
