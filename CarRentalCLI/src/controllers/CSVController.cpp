#include "controllers/CSVController.h"
#include "models/CustomerModel.h"
#include <rapidcsv.h>
#include <iostream>
#include <vector>
#include <string>
#include "storage.h"
#include "models/CarModel.h"

bool CSVController::ExportToCSV(const std::string& filename)
{
    try
    {
        std::vector<RentalModel> rentals = storage.get_all<RentalModel>();

        // Sjekk at filbanen er riktig
        std::string path = "./" + filename;
        std::cout << "Saving file to: " << path << std::endl;  // Debugging

        // Tomt dokument (in-memory)
        rapidcsv::Document doc("", rapidcsv::LabelParams(-1, -1));

        // Header
        std::vector<std::string> header = {
            "rentalID", "customerID", "customerName", "customerTel", "customerEmail",
            "carID", "regNo", "brand", "model", "startDate", "endDate"
        };
        doc.SetRow(0, header);

        // Data
        for (size_t i = 0; i < rentals.size(); ++i)
        {
            const auto& rental = rentals[i];
            auto customer = storage.get<CustomerModel>(rental.customerID);
            auto car = storage.get<CarModel>(rental.carID);

            std::vector<std::string> row = {
                std::to_string(rental.rentalID),
                std::to_string(customer.customerID),
                customer.name,
                customer.tel,
                customer.email,
                std::to_string(car.carID),
                car.regNo,
                car.brand,
                car.model,
                rental.dateRented,
                rental.dateReturned
            };

            doc.SetRow(i + 1, row);  // +1 fordi header er på rad 0
        }

        // Lagre filen
        doc.Save(path);  // Bruker relatert sti her
        return true;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error exporting all data to CSV: " << e.what() << std::endl;
        return false;
    }
}