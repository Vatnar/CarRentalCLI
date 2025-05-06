#pragma once
#include <string>

class RentalModel
{
public:
	int rentalID;
	int customerID;
	int carID;
	std::string dateRented;
	std::string dateReturned;
};