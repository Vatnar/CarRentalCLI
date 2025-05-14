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

bool CustomerController::editCustomer(int customerID, std::string& newName, std::string& newTel, std::string& newEmail)
{
    auto customer = storage.get<CustomerModel>(customerID);

    customer.name = newName;
    customer.tel = newTel;
    customer.email = newEmail;

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
    std::vector<CustomerModel> customers = storage.get_all<CustomerModel>(
        where(like(&CustomerModel::name, likePhrase)));

    return customers;
}