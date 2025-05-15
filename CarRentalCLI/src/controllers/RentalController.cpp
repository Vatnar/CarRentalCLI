#include "controllers/RentalController.h"
#include "storage.h"
#include "Utils.h"
#include "models/RentalModel.h"
#include <iostream>
#include <rapidcsv.h>
#include <fstream>


/**
 * @brief Registers a new car rental in the database.
 *
 * @param customerID ID of the customer renting the car.
 * @param carID ID of the car being rented.
 * @param startDate Start date of the rental (format: YYYY-MM-DD hh-mm).
 * @param endDate End date of the rental (format: YYYY-MM-DD hh-mm).
 * @return true if the rental was successfully registered, false otherwise.
 */
bool RentalController::RentCar(int customerID, int carID, const std::string& startDate, const std::string& endDate)
{
    try
    {
        RentalModel newRental{-1, customerID, carID, startDate, endDate};
        newRental.rentalID = storage.insert(newRental);
        std::cout << "Rental registered successfully" << std::endl;
        return true;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error in RentCar: " << e.what() << std::endl;
        return false;
    }
}


/**
 * @brief Returns a car by setting the end date of a rental.
 *
 * @param rentalID ID of the rental to update.
 * @param returnDate The date the car was returned (format: YYYY-MM-DD hh-mm).
 * @return true if the rental was successfully updated, false otherwise.
 */
bool RentalController::ReturnCar(int rentalID, const std::string& returnDate)
{
    try
    {
        auto rent = storage.get<RentalModel>(rentalID);
        rent.endDate = returnDate;
        storage.update(rent);
        std::cout << "Storage updated successfully" << std::endl;
        return true;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error in ReturnCar: " << e.what() << std::endl;
        return false;
    }
}


/**
 * @brief Counts all registered rentals.
 *
 * @return Total number of rentals.
 */
int RentalController::CountRentals()
{
    try
    {
        return storage.count<RentalModel>();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error in CountRentals: " << e.what() << std::endl;
        return 0;
    }
}


/**
 * @brief Counts currently active rentals (with a start date, but no end date).
 *
 * @return Number of active rentals.
 */
int RentalController::CountActiveRentals()
{
    try
    {
        const std::string currentTime = Time::GetCurrentTime();

        auto count = storage.count<RentalModel>(where(
            c(&RentalModel::endDate) > currentTime)
            );
        return count;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error in CountActiveRentals: " << e.what() << std::endl;
        return 0;
    }
}


/**
 * @brief Counts rentals that have been completed (returned before the current time).
 *
 * @return Number of completed rentals.
 */
int RentalController::CountCompletedRentals()
{
    const std::string currentTime = Time::GetCurrentTime();

    try
    {
        auto completedRentalCount = storage.count<RentalModel>(
            where(c(&RentalModel::endDate) < currentTime)
        );
        return completedRentalCount;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error in CountCompletedRentals: " << e.what() << std::endl;
        return 0;
    }
}


/**
 * @brief Searches for rentals based on a specified field and search value.
 *
 * @param searchPhrase Text input used for date fields.
 * @param field Field to search (0 = customerID, 1 = carID, 2 = startDate, 3 = endDate, 4 = all).
 * @param ID Used when searching customerID or carID.
 * @return A vector of matching RentalModel entries.
 */
std::vector<RentalModel> RentalController::Search(
    const std::string &searchPhrase, int field, int ID)
{
    try
    {
        using namespace sqlite_orm;
        std::string likePhrase = "%" + searchPhrase + "%";

        switch (field)
        {
        case 0:
            return storage.get_all<RentalModel>(
                where(c(&RentalModel::customerID) == ID));
        case 1:
            return storage.get_all<RentalModel>(
                where(c(&RentalModel::carID) == ID));
        case 2:
            return storage.get_all<RentalModel>(
                where(like(&RentalModel::startDate, likePhrase)));
        case 3:
            return storage.get_all<RentalModel>(
                where(like(&RentalModel::endDate, likePhrase)));
        case 4:
            return storage.get_all<RentalModel>();
        default:
            std::cerr << "Invalid field\n";
            return {};
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error in Search: " << e.what() << std::endl;
        return {};
    }
}


/**
 * @brief Updates an existing rental with new values.
 *
 * @param rentalID ID of the rental to update.
 * @param newStartDate New start date (format: YYYY-MM-DD hh-mm).
 * @param newEndDate New end date (format: YYYY-MM-DD hh-mm).
 * @param newCustomerID New customer ID.
 * @param newCarID New car ID.
 * @return true if the rental was successfully updated, false otherwise.
 */
bool RentalController::EditRental(int rentalID, const std::string& newStartDate, const std::string& newEndDate, int newCustomerID, int newCarID)
{
    try
    {
        auto rent = storage.get<RentalModel>(rentalID);

        rent.startDate = newStartDate;
        rent.endDate = newEndDate;
        rent.customerID = newCustomerID;
        rent.carID = newCarID;
        storage.update(rent);

        std::cout << "Rental updated successfully" << std::endl;
        return true;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error in EditRental: " << e.what() << std::endl;
        return false;
    }
}


/**
 * @brief Deletes a rental from the database.
 *
 * @param rentalID ID of the rental to remove.
 * @return true if the rental was successfully removed, false otherwise.
 */
bool RentalController::RemoveRental(int rentalID)
{
    try
    {
        storage.remove<RentalModel>(rentalID);

        std::cout << "Rental removed successfully" << std::endl;
        return true;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error in RemoveRental: " << e.what() << std::endl;
        return false;
    }
}


/**
 * @brief Retrieves a rental by its ID.
 *
 * @param rentalID The ID of the rental to retrieve.
 * @return The RentalModel if found, or std::nullopt if not found.
 */
std::optional<RentalModel> RentalController::GetRentalById(int rentalID)
{
    try
    {
        return storage.get<RentalModel>(rentalID);
    }
    catch (const std::exception&)
    {
        return std::nullopt;
    }
}