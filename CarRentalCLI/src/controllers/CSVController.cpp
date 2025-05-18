#include "controllers/CSVController.h"
#include "models/CustomerModel.h"
#include <rapidcsv.h>
#include <iostream>
#include <vector>
#include <string>
#include "storage.h"
#include "models/CarModel.h"

/**
* @brief Exports all customers, cars, and rentals into a unified CSV file.
*
* @param filename The name of the CSV file to save (e.g., "data.csv").
* @return true if export succeeds, false otherwise.
*/
bool CSVController::ExportToCSV(const std::string &filename)
{
    try
    {
        int rowNumber = 0;

        // Compose full file path (relative to current directory)
        std::string path = "./" + filename;
        std::cout << "Saving file to: " << path << std::endl;

        // Create a new in-memory CSV document with no headers or labels
        rapidcsv::Document doc("", rapidcsv::LabelParams(-1, -1));

        // Header row: columns for rentals, customers, and cars combined
        std::vector<std::string> header = {
            "rentalID", "customerID", "customerName", "customerTel",
            "customerEmail",
            "carID", "regNo", "brand", "model", "startDate", "endDate"
        };
        doc.SetRow(rowNumber++, header); // Set header row

        // Get all customers from storage and export them
        auto customers = storage.get_all<CustomerModel>();
        for (auto customer : customers)
        {
            std::vector<std::string> row = {
                "", // rentalID
                std::to_string(customer.customerID),
                customer.name,
                customer.tel,
                customer.email,
                "", "", "", "", "", "" // Empty car/rental fields
            };
            doc.SetRow(rowNumber++, row);
        }

        // Get all cars from storage and export them
        auto cars = storage.get_all<CarModel>();
        for (auto car : cars)
        {
            std::vector<std::string> row = {
                "", "", "", "", "", // rental and customer fields
                std::to_string(car.carID),
                car.regNo,
                car.brand,
                car.model,
                "", "" // Empty rental date fields
            };
            doc.SetRow(rowNumber++, row);
        }

        // Get all rentals from storage and export them
        auto rentals = storage.get_all<RentalModel>();
        for (auto rental : rentals)
        {
            std::vector<std::string> row = {
                std::to_string(rental.rentalID),
                std::to_string(rental.customerID),
                "", "", "", // customer info not included here
                std::to_string(rental.carID),
                "", "", "", // car info not included here
                rental.startDate,
                rental.endDate
            };
            doc.SetRow(rowNumber++, row);
        }

        // Save the in-memory CSV document to disk
        doc.Save(path);
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error exporting all data to CSV: " << e.what() << std::endl;
        return false;
    }
}

/**
* @brief Imports customers, cars, and rentals from a unified CSV file.
*
* Assumes each row belongs to only one data type.
* Fields that are not relevant should be empty.
*
* @param filename The name of the CSV file to read from (e.g., "data.csv").
* @return true if import is successful, false otherwise.
*/
bool CSVController::ImportFromCSV(const std::string &filename)
{
    try
    {
        std::string path = "./" + filename;
        std::cout << "Reading file from: " << path << std::endl;

        // Open CSV file for reading with no headers
        rapidcsv::Document doc(path, rapidcsv::LabelParams(-1, -1));
        int rowCount = doc.GetRowCount();

        // Start from 1 to skip header
        for (int i = 1; i < rowCount; ++i)
        {
            std::vector<std::string> row = doc.GetRow<std::string>(i);

            // Extract fields by column index
            std::string rentalID      = row[0];
            std::string customerID    = row[1];
            std::string customerName  = row[2];
            std::string customerTel   = row[3];
            std::string customerEmail = row[4];
            std::string carID         = row[5];
            std::string regNo         = row[6];
            std::string brand         = row[7];
            std::string model         = row[8];
            std::string startDate     = row[9];
            std::string endDate       = row[10];

            // If it's a customer row (has customer ID and name)
            if (!customerID.empty() && !customerName.empty())
            {
                CustomerModel customer;
                customer.customerID = std::stoi(customerID);
                customer.name       = customerName;
                customer.tel        = customerTel;
                customer.email      = customerEmail;
                storage.insert(customer);
            }
            // If it's a car row (has car ID and reg number)
            else if (!carID.empty() && !regNo.empty())
            {
                CarModel car;
                car.carID = std::stoi(carID);
                car.regNo = regNo;
                car.brand = brand;
                car.model = model;
                storage.insert(car);
            }
            // If it's a rental row (has rental ID and dates)
            else if (!rentalID.empty() && !startDate.empty())
            {
                RentalModel rental;
                rental.rentalID   = std::stoi(rentalID);
                rental.customerID = std::stoi(customerID);
                rental.carID      = std::stoi(carID);
                rental.startDate  = startDate;
                rental.endDate    = endDate;
                storage.insert(rental);
            }
        }

        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error importing data from CSV: " << e.what() << std::endl;
        return false;
    }
}
