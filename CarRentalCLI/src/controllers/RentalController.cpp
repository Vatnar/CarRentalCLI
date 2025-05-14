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
int RentalController::CountActiveRentals()
{
    auto activeRentalCount = storage.count<RentalModel>(
        where(is_not_null(&RentalModel::startDate) and is_null(&RentalModel::endDate))
    );
    return activeRentalCount;
}


int RentalController::CountCompletedRentals()
{
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

void RentalController::EditRental(int rentalID, const std::string& newStartDate, const std::string& newEndDate, int newCustomerID, int newCarID)
{
    auto rent = storage.get<RentalModel>(rentalID);

    // Oppdater feltene med de nye verdiene
    rent.startDate = newStartDate;
    rent.endDate = newEndDate;
    rent.customerID = newCustomerID;
    rent.carID = newCarID;

    // Oppdater lagret leieavtale
    storage.update(rent);
    std::cout << "Rental updated successfully" << std::endl;
}

void RentalController::RemoveRental(int rentalID)
{
    // Hent leieavtalen med det gitte rentalID
    auto rent = storage.get<RentalModel>(rentalID);

    // Slett leieavtalen fra lagringen
    storage.remove(rent);
    std::cout << "Rental removed successfully" << std::endl;
}