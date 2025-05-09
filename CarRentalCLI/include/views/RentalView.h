#pragma once
#include <string>

#include "View.h"
#include "controllers/CarController.h"
#include "controllers/CustomerController.h"
#include "controllers/RentalController.h"


class RentalView : public View {
public:
    RentalView();

    /**
     * @brief Run's the GUI of the view and logic
     */
    void Run() override;

protected:
    int getCustomerID();

    int getCarID(const std::string &startDate, const std::string &endDate);

    bool matchesPattern(const std::string &s);

    std::string getCurrentDateTime();

    std::string getEndDate();

    int getRentalID();

    std::string getStartdate();

    void addRental();

    void editRental();

    void removeRental();
    std::string rentalMenu = R"MENU(
==================================
            RENTALS
==================================
        1. ADD NEW RENTAL
        2. EDIT RENTAL
        3. REMOVE RENTAL
        4. Exit
==================================
Please enter your choice:
)MENU";
    RentalController rentalController;
    CustomerController customerController;
    CarController carController;
};



