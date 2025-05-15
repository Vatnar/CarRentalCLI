#pragma once
#include <string>

/**
 * Representation of customer in database
 */
class CustomerModel
{
public:
    int         customerID;
    std::string name;
    std::string tel;
    std::string email;
};
