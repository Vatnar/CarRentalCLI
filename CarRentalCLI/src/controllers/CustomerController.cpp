#include "controllers/CustomerController.h"
#include "models/CustomerModel.h"
#include "storage.h"
#include <iostream>
#include <rapidcsv.h>
#include <fstream>


/**
 * @brief Adds a new customer to the storage.
 *
 * The customer will be assigned a unique customerID upon successful insertion.
 *
 * @param name The name of the customer.
 * @param tel The telephone number of the customer.
 * @param email The email address of the customer.
 * @return true if the customer was added successfully, false if an error occurred.
 */
bool CustomerController::AddCustomer(
    const std::string &name, const std::string &tel, const std::string &email)
{
    CustomerModel newCustomer{-1, name, tel, email};

    try
    {
        newCustomer.customerID = storage.insert(newCustomer);
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}


/**
 * @brief Edits an existing customer's details.
 *
 * The customer is identified by their customerID, and their name, phone number, and email are updated.
 *
 * @param customerID The ID of the customer to be edited.
 * @param newName The new name for the customer.
 * @param newTel The new phone number for the customer.
 * @param newEmail The new email address for the customer.
 * @return true if the customer was successfully updated, false if an error occurred.
 */
bool CustomerController::EditCustomer(
    int          customerID, std::string &newName, std::string &newTel,
    std::string &newEmail)
{
    auto customer = storage.get<CustomerModel>(customerID);

    customer.name  = newName;
    customer.tel   = newTel;
    customer.email = newEmail;

    try
    {
        storage.update(customer);
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}


/**
 * @brief Removes a customer from the storage.
 * *
 * @param customerID The ID of the customer to be removed.
 * @return true if the customer was successfully removed, false if an error occurred.
 */
bool CustomerController::RemoveCustomer(int customerID)
{
    try
    {
        storage.remove<CustomerModel>(customerID);
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}


/**
 * @brief Counts the total number of customers in the storage.
 * *
 * @return The total number of customers in the storage.
 */
int CustomerController::CountCustomers()
{
    auto customerCount = storage.count<CustomerModel>();
    return customerCount;
}


/**
 * @brief Searches for customers by name.
 *
 * This function searches for customers whose name contains the given search phrase.
 *
 * @param searchPhrase The phrase to search for in the customer's name.
 * @return A vector of customers matching the search criteria.
 */
std::vector<CustomerModel> CustomerController::SearchCustomer(
    const std::string &searchPhrase)
{
    std::string                likePhrase = "%" + searchPhrase + "%";
    std::vector<CustomerModel> customers  = storage.get_all<CustomerModel>(
        where(like(&CustomerModel::name, likePhrase)));

    return customers;
}


/**
 * @brief Retrieves a customer by its ID.
 *
 * @param customerID The ID of the customer to retrieve.
 * @return The CustomerModel if found, or std::nullopt if not found.
 */
std::optional<CustomerModel> CustomerController::GetCustomerById(int id)
{
    try
    {
        auto customer = storage.get<CustomerModel>(id);
        return customer;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error in GetCustomerById: " << e.what() << std::endl;
        return std::nullopt;
    }
}
