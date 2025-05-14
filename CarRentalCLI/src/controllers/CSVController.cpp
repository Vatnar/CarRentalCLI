//
// Created by roem0 on 14.05.2025.
//

#include "CSVController.h"


/**
 * @brief Exports all cars from the database to a CSV file.
 *
 * @param filename Name of the CSV file to create (e.g., "cars.csv").
 * @return true if export succeeds, false otherwise.
 */
bool CSVController::ExportCarsToCSV(const std::string& filename)
{
    try
    {
        std::vector<CarModel> cars = storage.get_all<CarModel>();

        std::ofstream file(filename);
        if (!file.is_open())
        {
            std::cerr << "Failed to create file: " << filename << std::endl;
            return false;
        }

        file << "carID,regNo,brand,model\n";
        for (const auto& car : cars)
        {
            file << car.carID << ","
                 << car.regNo << ","
                 << car.brand << ","
                 << car.model << "\n";
        }

        file.close();
        return true;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error exporting cars to CSV: " << e.what() << std::endl;
        return false;
    }
}


/**
 * @brief Exports all customers from the database to a CSV file.
 *
 * @param filename Name of the CSV file to create (e.g., "customers.csv").
 * @return true if export succeeds, false otherwise.
 */
bool CSVController::ExportCustomersToCSV(const std::string& filename)
{
    try
    {
        std::vector<CustomerModel> customers = storage.get_all<CustomerModel>();

        std::ofstream file(filename);
        if (!file.is_open())
        {
            std::cerr << "Failed to create file: " << filename << std::endl;
            return false;
        }

        file << "customerID,name,tel,email\n";
        for (const auto& customer : customers)
        {
            file << customer.customerID << ","
                 << customer.name << ","
                 << customer.tel << ","
                 << customer.email << "\n";
        }

        file.close();
        return true;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error exporting customers to CSV: " << e.what() << std::endl;
        return false;
    }
}


/**
 * @brief Exports all rentals from the database to a CSV file.
 *
 * @param filename Name of the CSV file to create (e.g., "rentals.csv").
 * @return true if export succeeds, false otherwise.
 */
bool CSVController::ExportRentalsToCSV(const std::string& filename)
{
    try
    {
        std::vector<RentalModel> rentals = storage.get_all<RentalModel>();

        std::ofstream file(filename);
        if (!file.is_open())
        {
            std::cerr << "Failed to create file: " << filename << std::endl;
            return false;
        }

        file << "rentalID,customerID,carID,startDate,endDate\n";

        for (const auto& rental : rentals)
        {
            file << rental.rentalID << ","
                 << rental.customerID << ","
                 << rental.carID << ","
                 << rental.startDate << ","
                 << rental.endDate << "\n";
        }

        file.close();
        return true;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error exporting rentals to CSV: " << e.what() << std::endl;
        return false;
    }
}