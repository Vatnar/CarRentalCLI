#pragma once
#include <string>

#include "CarView.h"
#include "CustomerView.h"
#include "View.h"
#include "controllers/CarController.h"
#include "controllers/CustomerController.h"
#include "controllers/RentalController.h"


class RentalView : public View
{
public:
    RentalView(const CustomerView &customerView, const CarView &carView);

    /**
     * @brief Run's the GUI of the view and logic
     */
    void Run() override;

private:
    /**
     *
     * @return id of prompted customer
     */
    int getCustomerID();

    /**
     * @brief Lists cars based on string input and dates
     * @param startDate start of rental
     * @param endDate end of rental
     * @return ID of car
     */
    int getCarID(const std::string &startDate, const std::string &endDate);

    /**
     * @brief Checks if string matched datetime format
     * @param s string to check
     * @return true if it matches
     */
    bool matchesPattern(const std::string &s);


    /**
     * Prompts user for datetime
     * @return string entered
     */
    std::string getEndDate();

    /**
     *
     * @return id of prompted car
     */
    int getRentalID();

    /**
     * prompt user for endate
     * @return string entered
     */
    std::string getStartdate();


    void addRental();

    void editRental();

    void removeRental();

    void listRentals();

    std::string        rentalMenu = R"MENU(
==================================
            RENTALS
==================================
        1. ADD NEW RENTAL
        2. EDIT RENTAL
        3. REMOVE RENTAL
        4. LIST RENTALS
        5. RETURN TO MENU
==================================
Please enter your choice:
)MENU";
    RentalController   rentalController;
    CustomerController customerController;
    CustomerView       customerView;
    CarController      carController;
    CarView            carView;
};



