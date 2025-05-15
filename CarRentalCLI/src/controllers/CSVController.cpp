#include "controllers/CSVController.h"
#include "models/CustomerModel.h"
#include <rapidcsv.h>
#include <iostream>
#include <vector>
#include <string>
#include "storage.h"
#include "models/CarModel.h"

bool CSVController::ExportToCSV(const std::string &filename)
{
    try
    {
        int rowNumber = 0;

        // Sjekk at filbanen er riktig
        std::string path = "./" + filename;
        std::cout << "Saving file to: " << path << std::endl; // Debugging

        // Tomt dokument (in-memory)
        rapidcsv::Document doc("", rapidcsv::LabelParams(-1, -1));

        // Header
        std::vector<std::string> header = {
            "rentalID", "customerID", "customerName", "customerTel",
            "customerEmail",
            "carID", "regNo", "brand", "model", "startDate", "endDate"
        };
        doc.SetRow(rowNumber++, header);

        auto customers = storage.get_all<CustomerModel>();
        auto cars      = storage.get_all<CarModel>();
        auto rentals   = storage.get_all<RentalModel>();

        for (auto customer: customers)
        {
            std::vector<std::string> row = {
                "",
                std::to_string(customer.customerID),
                customer.name,
                customer.tel,
                customer.email,
                "",
                "",
                "",
                "",
                "",
                ""
            };
            doc.SetRow(rowNumber++, row);
        }

        for (auto car: cars)
        {
            std::vector<std::string> row = {
                "",
                "",
                "",
                "",
                "",
                std::to_string(car.carID),
                car.regNo,
                car.brand,
                car.model,
                "",
                ""
            };
            doc.SetRow(rowNumber++, row);
        }

        for (auto rental: rentals)
        {
            std::vector<std::string> row = {
                std::to_string(rental.rentalID),
                std::to_string(rental.customerID),
                "",
                "",
                "",
                std::to_string(rental.carID),
                "",
                "",
                "",
                rental.startDate,
                rental.endDate
            };

            doc.SetRow(rowNumber++, row);
        }

        doc.Save(path);
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error exporting all data to CSV: " << e.what() <<
                std::endl;
        return false;
    }
}

bool CSVController::ImportFromCSV(const std::string &filename)
{
    try
    {
        std::string path = "./" + filename;
        std::cout << "Reading file from: " << path << std::endl;

        rapidcsv::Document doc(path, rapidcsv::LabelParams(-1, -1));
        int                rowCount = doc.GetRowCount();

        for (int i = 1; i < rowCount; ++i)
        // not range based so we can skip header
        {
            std::vector<std::string> row = doc.GetRow<std::string>(i);

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

            if (!customerID.empty() && !customerName.empty())
            {
                CustomerModel customer;
                customer.customerID = std::stoi(customerID);
                customer.name       = customerName;
                customer.tel        = customerTel;
                customer.email      = customerEmail;
                storage.insert(customer);
            } else if (!carID.empty() && !regNo.empty())
            {
                CarModel car;
                car.carID = std::stoi(carID);
                car.regNo = regNo;
                car.brand = brand;
                car.model = model;
                storage.insert(car);
            } else if (!rentalID.empty() && !startDate.empty())
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

