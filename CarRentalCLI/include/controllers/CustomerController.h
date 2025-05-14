#pragma once
#include "models/CustomerModel.h"
#include <string>
#include <vector>
#include <optional>

/**
 * @brief Modifies and reads the Customer table
 */
class CustomerController
{
public:
    bool addCustomer(const std::string& name, const std::string& tel, const std::string& email);
    bool editCustomer(int id, std::string& name, std::string& tel, std::string& email);
    bool removeCustomer(int id);

    int countCustomers();

    std::optional<CustomerModel> getCustomerByID(int customerID);
    std::vector<CustomerModel> searchCustomer(const std::string& searchPhrase);
};