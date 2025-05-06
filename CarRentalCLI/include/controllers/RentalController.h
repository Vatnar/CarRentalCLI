        #pragma once
#include <string>

/**
 * @brief Modifies and reads the Rental table
 */
class RentalController
{
    public:
    void rentCar(int customerID, int carID, const std::string& rentalDate);
    void returnCar(const int rentalID, const std::string& returnDate);

    int countActiveRentals();
    int countCompletedRentals();
};