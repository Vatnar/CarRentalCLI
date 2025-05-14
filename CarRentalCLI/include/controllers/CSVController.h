#pragma once
#include <string>

class CSVController
{
public:
    bool ExportCarsToCSV(const std::string& filename);
    bool ExportCustomersToCSV(const std::string& filename);
    bool ExportRentalsToCSV(const std::string& filename);

    bool ImportCarsFromCSV(const std::string& filename);
    bool ImportCustomersFromCSV(const std::string& filename);
    bool ImportRentalsFromCSV(const std::string& filename);
};