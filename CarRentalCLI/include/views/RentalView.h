#ifndef RENTALVIEW_H
#define RENTALVIEW_H
#include <string>

#include "controllers/CarController.h"
#include "controllers/CustomerController.h"
#include "controllers/RentalController.h"


class RentalView {
public:
    RentalView();

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



#endif //RENTALVIEW_H
