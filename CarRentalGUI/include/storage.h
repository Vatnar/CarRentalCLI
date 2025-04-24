#ifndef STORAGE_H
#define STORAGE_H

#include <sqlite_orm.h>
#include "Car.h"
#include "Customer.h"
using namespace sqlite_orm;



inline auto init_storage()
{
    auto storage = make_storage("CarRental.sqlite",
                                make_table("Customer",
                                    make_column("customerID", &Customer::customerID, primary_key().autoincrement()),
                                    make_column("name", &Customer::name, not_null()),
                                    make_column("tel", &Customer::tel),
                                    make_column("birthdate", &Customer::birthDate)
                                ),
                                make_table("Car",
                                    make_column("carID",&Car::carID, primary_key().autoincrement()),
                                    make_column("regNo", &Car::regNo),
                                    make_column("brand", &Car::brand),
                                    make_column("model", &Car::model),
                                    make_column("customerID", &Car::customerID),
                                    foreign_key(&Car::customerID).references(&Customer::customerID)
                                ));

    return storage;
}
using Storage = decltype(init_storage());
#endif //STORAGE_H
