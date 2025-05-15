#pragma once
#include <sqlite_orm.h>
#include "models/CarModel.h"
#include "models/CustomerModel.h"
#include "models/rentalModel.h"
using namespace sqlite_orm;

inline auto init_storage()
{
    auto storage = make_storage(
        "CarRental.sqlite",
        make_table(
            "Customer",
            make_column(
                "customerID", &CustomerModel::customerID,
                primary_key().autoincrement()),
            make_column("name", &CustomerModel::name),
            make_column("tel", &CustomerModel::tel),
            make_column("email", &CustomerModel::email)
        ),
        make_table(
            "Car",
            make_column(
                "carID", &CarModel::carID, primary_key().autoincrement()),
            make_column("regNo", &CarModel::regNo),
            make_column("brand", &CarModel::brand),
            make_column("model", &CarModel::model)
        ),
        make_table(
            "Rental",
            make_column(
                "rentalID", &RentalModel::rentalID,
                primary_key().autoincrement()),
            make_column("customerID", &RentalModel::customerID, not_null()),
            make_column("carID", &RentalModel::carID, not_null()),
            make_column("startDate", &RentalModel::startDate),
            make_column("endDate", &RentalModel::endDate)
        ));
    return storage;
}

using Storage       = decltype(init_storage());
inline auto storage = init_storage();
