        #pragma once
#include <string>
#include <vector>

#include "models/CarModel.h"
#include "models/rentalModel.h"

        /**
 * @brief Modifies and reads the Rental table
 */
class RentalController
{
    public:
    void rentCar(int customerID, int carID, const std::string &startDate, const std::string &endDate);
    void returnCar(const int rentalID, const std::string& returnDate);

    int CountRentals();
    int CountActiveRentals();
    int CountCompletedRentals();

    std::vector<RentalModel> search(const std::string &searchPhrase, int field, int ID = -1);

    void EditRental(int rentalID, const std::string& startDate, const std::string& endDate, int customerID, int carID);
    void RemoveRental(int rentalID);
};