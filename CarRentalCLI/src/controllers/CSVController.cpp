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


/**
 * @brief Imports car data from a CSV file and inserts it into the database.
 *
 * @param filename Name of the CSV file to read (e.g., "cars.csv").
 * @return true if import succeeds, false otherwise.
 */
bool CSVController::ImportCarsFromCSV(const std::string& filename)
{
    try
    {
        rapidcsv::Document doc(filename, rapidcsv::LabelParams(0, -1));

        std::vector<int> carIDs = doc.GetColumn<int>("carID");
        std::vector<std::string> regNos = doc.GetColumn<std::string>("regNo");
        std::vector<std::string> brands = doc.GetColumn<std::string>("brand");
        std::vector<std::string> models = doc.GetColumn<std::string>("model");

        for (size_t i = 0; i < carIDs.size(); ++i)
        {
            CarModel car { carIDs[i], regNos[i], brands[i], models[i] };
            storage.insert(car);
        }

        return true;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error importing cars from CSV: " << e.what() << std::endl;
        return false;
    }
}


/**
 * @brief Imports customer data from a CSV file and inserts it into the database.
 *
 * @param filename Name of the CSV file to read (e.g., "customers.csv").
 * @return true if import succeeds, false otherwise.
 */
bool CSVController::ImportCustomersFromCSV(const std::string& filename)
{
    try
    {
        rapidcsv::Document doc(filename, rapidcsv::LabelParams(0, -1));

        std::vector<int> customerIDs = doc.GetColumn<int>("customerID");
        std::vector<std::string> names = doc.GetColumn<std::string>("name");
        std::vector<std::string> tels = doc.GetColumn<std::string>("tel");
        std::vector<std::string> emails = doc.GetColumn<std::string>("email");

        for (size_t i = 0; i < customerIDs.size(); ++i)
        {
            CustomerModel customer { customerIDs[i], names[i], tels[i], emails[i] };
            storage.insert(customer);
        }

        return true;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error importing customers from CSV: " << e.what() << std::endl;
        return false;
    }
}


/**
 * @brief Imports rental data from a CSV file and inserts it into the database.
 *
 * @param filename Name of the CSV file to read (e.g., "rentals.csv").
 * @return true if import succeeds, false otherwise.
 */
bool CSVController::ImportRentalsFromCSV(const std::string& filename)
{
    try
    {
        rapidcsv::Document doc(filename, rapidcsv::LabelParams(0, -1));

        std::vector<int> rentalIDs = doc.GetColumn<int>("rentalID");
        std::vector<int> customerIDs = doc.GetColumn<int>("customerID");
        std::vector<int> carIDs = doc.GetColumn<int>("carID");
        std::vector<std::string> startDates = doc.GetColumn<std::string>("startDate");
        std::vector<std::string> endDates = doc.GetColumn<std::string>("endDate");

        for (size_t i = 0; i < rentalIDs.size(); ++i)
        {
            RentalModel rental { rentalIDs[i], customerIDs[i], carIDs[i], startDates[i], endDates[i] };
            storage.insert(rental);
        }

        return true;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error importing rentals from CSV: " << e.what() << std::endl;
        return false;
    }
}
