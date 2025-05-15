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
    /**
     *
     * @param name name of custoemr
     * @param tel telephone number of customer
     * @param email email of customer
     * @return true if succeeded
     */
    bool AddCustomer(
        const std::string &name, const std::string &tel,
        const std::string &email);

    /**
     *
     * @param id id of customer to edit
     * @param name new name of customer
     * @param tel new telephone number of customer
     * @param email new email of customer
     * @return true if succeeded
     */
    bool EditCustomer(
        int id, std::string &name, std::string &tel, std::string &email);

    /**
     *
     * @param id id of customer to remove
     * @return true if suceeded
     */
    bool RemoveCustomer(int id);

    /**
     *
     * @return count of customers
     */
    int CountCustomers();

    /**
     *
     * @param customerID id of customer to fetch
     * @return instance of customermodel with that id
     */
    std::optional<CustomerModel> GetCustomerById(int customerID);

    /**
     *
     * @param searchPhrase phrase to search for "" is supported
     * @return list of customers fitting the query
     */
    std::vector<CustomerModel> SearchCustomer(const std::string &searchPhrase);
};
