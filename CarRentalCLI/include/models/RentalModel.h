#pragma once
#include <string>

/**
 * representation of rental in database
 */
class RentalModel
{
public:
	int         rentalID;
	int         customerID;
	int         carID;
	std::string startDate;
	std::string endDate;
};
