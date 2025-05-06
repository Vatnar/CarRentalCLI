#include "controllers/RentalController.h"
#include "models/RentalModel.h"
#include "storage.h"

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