#include "controllers/CustomerController.h"
#include "models/CustomerModel.h"
#include "storage.h"
#include <iostream>

bool CustomerController::addCustomer(const std::string& name, const std::string& tel, const std::string& email)
{
    CustomerModel newCustomer {-1, name, tel, email};

    try {
        newCustomer.customerID = storage.insert(newCustomer);
        return true;
    }
    catch (const std::exception& e) {
        return false;
    }
}

bool CustomerController::editCustomer(int customerID, std::string& name, std::string& tel, std::string& email)
{
    auto customer = storage.get<CustomerModel>(customerID);

    customer.name = name;
    customer.tel = tel;
    customer.email = email;

    try {
        storage.update(customer);
        return true;
    }
    catch (const std::exception& e) {
        return false;
    }
}

bool CustomerController::removeCustomer(int customerID)
{
    auto customer = storage.get<CustomerModel>(customerID);

    try {
        storage.remove<CustomerModel>(customerID);
        return true;
    }
    catch (const std::exception& e) {
        return false;
    }
}

int CustomerController::countCustomers()
{
    auto customerCount = storage.count<CustomerModel>();
    return customerCount;
}

std::vector<CustomerModel> CustomerController:: searchCustomer(const std::string& searchPhrase)
{
    std::string likePhrase = "%" + searchPhrase + "%";
    std::vector<CustomerModel> customerVector = storage.get_all<CustomerModel>(
        where(like(&CustomerModel::name, likePhrase))
    );

    return customerVector;
}