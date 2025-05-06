#include "controllers/CustomerController.h"
#include "models/CustomerModel.h"
#include "storage.h"
#include <iostream>

void CustomerController::addCustomer(std::string& name, std::string& tel, std::string& email)
{
    CustomerModel newCustomer {-1, name, tel, email};

    newCustomer.customerID = storage.insert(newCustomer);
    std::cout << __FILE__ << "Storage updated successfully" << std::endl;
}

void CustomerController::editCustomer(int customerID, std::string& name, std::string& tel, std::string& email)
{
    auto customer = storage.get<CustomerModel>(customerID);

    customer.name = name;
    customer.tel = tel;
    customer.email = email;

    storage.update(customer);
    std::cout << "Storage updated successfully" << std::endl;
}

void CustomerController::removeCustomer(int customerID)
{
    auto customer = storage.get<CustomerModel>(customerID);

    // TODO Trenger error handling i customer og
    storage.remove<CustomerModel>(customerID);
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

std::vector<CustomerModel> CustomerController::searchCustomer(std::string& searchPhrase)
{
    std::vector<CustomerModel> customerVector = storage.get_all<CustomerModel>(
        where(like(&CustomerModel::name, searchPhrase))
    );
    return customerVector;
}
