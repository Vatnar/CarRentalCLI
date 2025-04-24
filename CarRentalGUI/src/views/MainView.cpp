//
// Created by peter on 24/04/2025.
//
#include "views/MainView.h"
#include "Utils.h"
#include "views/CarView.h"
#include "views/CustomerView.h"
#include "views/RentalView.h"
#include "views/StatisticsView.h"
#include "views/ImportExportView.h"

MainView::MainView() {

    while (true)
    {
        std::cout << mainMenu;

        switch (Input::getInput(1, 5))
        {
            case 0: // not allowed
                break;
            case 1:
                {CustomerView customerView; break;}
            case 2:
                {CarView carView; break;}
            case 3:
                {RentalView rentalView; break;}
            case 4:
                {StatisticsView statisticsView; break;}
            case 5:
                {ImportExportView importExportView; break;}
            case 6:
                std::cout << "Exiting program...\n";
            exit(0);
        }
        std::cout << std::endl;
    }
}
