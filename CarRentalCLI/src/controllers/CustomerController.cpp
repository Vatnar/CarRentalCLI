#include "controllers/CustomerController.h"
#include "models/CustomerModel.h"
#include "storage.h"
#include <iostream>

void CustomerController::addCustomer(std::string name, std::string tel, std::string email)
{
    CustomerModel newCustomer {-1, name, tel, email};

    if (newCustomer.customerID = storage.insert(newCustomer))
        std::cout << "Storage updated successfully" << std::endl;
}

void CustomerController::editCustomer(int id, std::string name, std::string tel, std::string email)
{
    auto customer = storage.get<CustomerModel>(id);

    customer.name = name;
    customer.tel = tel;
    customer.email = email;

    storage.update(customer);
    std::cout << "Storage updated successfully" << std::endl;
}

void CustomerController::removeCustomer(int id)
{
    auto customer = storage.get<CustomerModel>(id);

    // TODO Trenger error handling i customer og
    storage.remove<CustomerModel>(id);
    std::cout << "Storage updated successfully" << std::endl;
}

int CustomerController::countCustomers()
{
    // Endret på denne, vet ikke om det er riktig da
    auto result = storage.select(count(&CustomerModel::customerID));
    if (!result.empty()) {
        std::cout << __FILE__ << ': Customer count: ' << result.front();
        return result.front();
    }
}

