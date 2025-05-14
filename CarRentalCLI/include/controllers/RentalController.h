#pragma once
#include <string>
#include <vector>

#include "models/rentalModel.h"

/**
 * @brief Modifies and reads the Rental table.
 */
class RentalController
{
    public:
    bool rentCar(int customerID, int carID, const std::string &startDate, const std::string &endDate);
    bool returnCar(int rentalID, const std::string& returnDate);

    int countRentals();
    int countActiveRentals();
    int countCompletedRentals();

    std::vector<RentalModel> Search(const std::string &searchPhrase, int field, int ID = -1);

    bool editRental(int rentalID, const std::string& startDate, const std::string& endDate, int customerID, int carID);
    bool removeRental(int rentalID);
};