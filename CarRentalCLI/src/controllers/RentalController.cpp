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

    rent.endDate = returnDate;

    storage.update(rent);
    std::cout << "Storage updated successfully" << std::endl;
}

int RentalController::CountRentals()
{

    return storage.count<RentalModel>();
}
int RentalController::countActiveRentals()
{
    //TODO Fix this

    // auto activeRentalCount = storage.count<RentalModel>(
    // where(is_not_null(&RentalModel::startDate) and is_null(&RentalModel::endDate))
    // );
    // return activeRentalCount;
    return 0;
}

int RentalController::countCompletedRentals()
{
    // TODO kan fort hende det krever noen modifikasjoner
    auto completedRentalCount = storage.count<RentalModel>(
        where(is_not_null(&RentalModel::endDate))
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
                where((&RentalModel::carID, ID)));
            break;
        case 2:
            rentals = storage.get_all<RentalModel>(
                where(like(&RentalModel::startDate, likePhrase)));
            break;
        case 3:
            rentals = storage.get_all<RentalModel>(
                where(like(&RentalModel::endDate, likePhrase)));
        case 4:
            rentals = storage.get_all<RentalModel>();
        default:
            std::cerr << "Invalid field\n";
        return {};
    }


    return rentals;
}

// TODO Add func to edit rentals
// TODO add func to remove rental