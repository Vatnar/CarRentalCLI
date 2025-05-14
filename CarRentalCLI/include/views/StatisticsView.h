#pragma once
#include <string>

#include "View.h"
#include "controllers/CarController.h"
#include "controllers/CustomerController.h"
#include "controllers/RentalController.h"

class StatisticsView: View {
public:
    StatisticsView();
    void Run() override;
private:

    CustomerController customerController;
    CarController carController;
    RentalController rentalController;


};
