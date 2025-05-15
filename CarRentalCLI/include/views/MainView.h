#pragma once
#include <iostream>
#include <ostream>

#include "CarView.h"
#include "CustomerView.h"
#include "ImportExportView.h"
#include "RentalView.h"
#include "StatisticsView.h"


class MainView : public View
{
public:
    MainView();

    void Run() override;

protected:
    std::string      mainMenu = R"MENU(
==================================
        CAR RENTAL SERVICE
==================================
        1. Customer Menu
        2. Car Menu
        3. Manage rentals
        4. Display statistics
        5. Import/Export
        6. EXIT
==================================
Please enter your choice:
)MENU";
    CustomerView     customerView;
    CarView          carView;
    RentalView       rentalView;
    StatisticsView   statisticsView;
    ImportExportView importExportView;
};

