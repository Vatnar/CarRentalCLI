#ifndef STORAGE_H
#define STORAGE_H

#include <vendor/sqlite_orm/sqlite_orm.h>

using namespace sqlite_orm;

class Customer
{
public:
    int customerID;
    std::string name;
    std::string tel;
    std::string birthDate;
};
class Car
{
public:
    int carID;
    std::string regNo;
    std::string brand;
    std::string model;
    int customerID;
};
inline auto init_storage()
{
    auto storage = make_storage("school.sqlite",
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
                                    make_column("customerID", &Car::customerID, foreign_key(&Customer::customerID))
                                ));

    return storage;
}
using Storage = decltype(init_storage());
#endif //STORAGE_H
