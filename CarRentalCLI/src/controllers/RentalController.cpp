#include "controllers/RentalController.h"
#include "models/RentalModel.h"
#include "storage.h"
#include "iostream"

void RentalController::rentCar(int customerID, int carID, std::string& rentalDate)
{
    RentalModel newRental {-1, customerID, carID, rentalDate};

    newRental.rentalID = storage.insert(newRental);
    std::cout << __FILE__ << "Rental registered successfully" << std::endl;
}

void RentalController::returnCar(int rentalID, std::string& returnDate)
{
    auto rent = storage.get<RentalModel>(rentalID);

    rent.dateReturned = returnDate;

    storage.update(rent);
    std::cout << "Storage updated successfully" << std::endl;
}

int RentalController::countActiveRentals()
{
    auto rentalCount = storage.count<RentalModel>(
        where(is_not_null(&RentalModel::dateRented) and is_null(&RentalModel::dateReturned))
    );
    return rentalCount;
}

int RentalController::countCompletedRentals()
{
    // TODO kan fort hende det krever noen modifikasjoner
    auto rentalCount = storage.count<RentalModel>(
        where(is_not_null(&RentalModel::dateReturned))
    );
    return rentalCount;
}