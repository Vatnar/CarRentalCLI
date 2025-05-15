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
    /**
     * @param customerID id of customer that rents
     * @param carID id of car to rent
     * @param startDate start date of rent period
     * @param endDate end date of rental period
     * @return true if succeeded
     */
    bool RentCar(
        int                customerID, int carID, const std::string &startDate,
        const std::string &endDate);

    /**
     * @return count of rentals
     */
    int CountRentals();

    /**
     * @return count of currently active rentals
     */
    int CountActiveRentals();

    /**
     * @return count of completed rentals
     */
    int CountCompletedRentals();

    /**
     * @param rentalID id of rental to fetch
     * @return RentalModel instance with that Id
     */
    std::optional<RentalModel> GetRentalById(int rentalID);

    /**
     * @param searchPhrase phrase to search
     * @param field what field to search for
     * @param ID Optional ID for searching
     * @return list of rentals matching the query
     */
    std::vector<RentalModel> Search(
        const std::string &searchPhrase, int field, int ID = -1);

    /**
     * @param rentalID id of rental to be edited
     * @param startDate new startDate
     * @param endDate new endDate
     * @param customerID new customerID
     * @param carID new carID
     * @return true if succeeded
     */
    bool EditRental(
        int rentalID, const std::string &startDate, const std::string &endDate,
        int customerID, int              carID);

    /**
     * @param rentalID
     * @return
     */
    bool RemoveRental(int rentalID);
};
