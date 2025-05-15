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
    bool AddCustomer(
        const std::string &name, const std::string &tel,
        const std::string &email);

    bool EditCustomer(
        int id, std::string &name, std::string &tel, std::string &email);

    bool RemoveCustomer(int id);

    int CountCustomers();

    std::optional<CustomerModel> GetCustomerById(int customerID);

    std::vector<CustomerModel> SearchCustomer(const std::string &searchPhrase);
};
