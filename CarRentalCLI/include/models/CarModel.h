#pragma once
#include <string>

/**
 * Representation of the model in database
 */
class CarModel
{
public:
    int         carID;
    std::string regNo;
    std::string brand;
    std::string model;
};
