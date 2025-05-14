#pragma once
#include <string>
#include <vector>
#include <optional>

#include "models/rentalModel.h"

/**
 * @brief Modifies and reads the Rental table.
 */
class RentalController
{
    public:
    bool rentCar(int customerID, int carID, const std::string &startDate, const std::string &endDate);
    bool returnCar(int rentalID, const std::string& returnDate);

    int CountRentals();
    int CountActiveRentals();
    int CountCompletedRentals();

    std::optional<RentalModel> getRentalByID(int rentalID);

    std::vector<RentalModel> Search(const std::string &searchPhrase, int field, int ID = -1);

    bool EditRental(int rentalID, const std::string& startDate, const std::string& endDate, int customerID, int carID);
    bool RemoveRental(int rentalID);
};