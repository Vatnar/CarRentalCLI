#include "controllers/RentalController.h"
#include "models/RentalModel.h"
#include "storage.h"
#include "iostream"

void RentalController::rentCar(int customerID, int carID, const std::string& startDate, const std::string& endDate)
{
    RentalModel newRental {-1, customerID, carID, startDate, endDate};

    newRental.rentalID = storage.insert(newRental);
    std::cout << __FILE__ << "Rental registered successfully" << std::endl;
}

void RentalController::returnCar(int rentalID, const std::string& returnDate)
{
    auto rent = storage.get<RentalModel>(rentalID);

    rent.dateReturned = returnDate;

    storage.update(rent);
    std::cout << "Storage updated successfully" << std::endl;
}

int RentalController::countActiveRentals()
{
    //TODO Fix this

    // auto activeRentalCount = storage.count<RentalModel>(
    // where(is_not_null(&RentalModel::dateRented) and is_null(&RentalModel::dateReturned))
    // );
    // return activeRentalCount;
    return 0;
}

int RentalController::countCompletedRentals()
{
    // TODO kan fort hende det krever noen modifikasjoner
    auto completedRentalCount = storage.count<RentalModel>(
        where(is_not_null(&RentalModel::dateReturned))
    );
    return completedRentalCount;
}

// TODO refactor all search to use datatype and not field, classes
std::vector<RentalModel> RentalController::search(
    const std::string &searchPhrase, int field, int ID)
{
    std::string likePhrase = "%" + searchPhrase + "%";
    std::vector<RentalModel> rentals;

    switch (field)
    {
        case 0:
            rentals = storage.get_all<RentalModel>(
                where((&RentalModel::customerID, ID)));
        break;
        case 1:
            rentals = storage.get_all<RentalModel>(
                where(like(&RentalModel::carID, likePhrase)));
        break;
        case 2:
            rentals = storage.get_all<RentalModel>(
                where(like(&RentalModel::dateRented, likePhrase)));
        break;
        default:
            std::cerr << "Invalid field\n";
        return {};
    }


    return rentals;
}