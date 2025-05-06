#pragma once
#include "models/CustomerModel.h"
#include <string>
#include <vector>

/**
 * @brief Modifies and reads the Customer table
 */
class CustomerController
{
public:
    void addCustomer(const std::string& name, const std::string& tel, const std::string& email);
    void editCustomer(int id, std::string& name, std::string& tel, std::string& email);
    void removeCustomer(int id);

    int countCustomers();

    std::vector<CustomerModel> searchCustomer(const std::string& searchPhrase);
};