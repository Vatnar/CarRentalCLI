#pragma once
#include "models/CustomerModel.h"
#include <string>
#include <vector>

class CustomerController
{
public:
    void addCustomer(std::string& name, std::string& tel, std::string& email);
    void editCustomer(int id, std::string& name, std::string& tel, std::string& email);
    void removeCustomer(int id);

    int countCustomers();

    std::vector<CustomerModel> searchCustomer(std::string& searchPhrase);
};