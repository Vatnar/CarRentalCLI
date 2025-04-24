#include "CustomerController.h"
#include "../models/CustomerModel.h"

void CustomerController::addCustomer(name, tel, birthDate)
{
    CustomerModel newCustomer {-1, name, tel, birthDate};

    if (newCustomer.id = storage.insert(newCustomer))
        std::cout << "Storage updated successfully" << std::endl;
}

void CustomerController::editCustomer(id, name, tel, birthDate)
{
    auto customer = storage.get<Customer>(id);

    customer.name = name;
    customer.tel = tel;
    customer.birthDate = birthDate;

    if (storage.update(customer))
        std::cout << "Storage updated successfully" << std::endl;
}

void CustomerController::removeCustomer(id)
{
    auto customer = storage.get<Customer>(id);

    if (storage.remove(customer))
        std::cout << "Storage updated successfully" << std::endl;
}

void CustomerController::countCustomers()
{
    auto customerCount = storage.select(count(id));
}