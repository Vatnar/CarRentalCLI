#pragma once
#include <string>

/**
 * @brief Import and export csv files
 */
class CSVController
{
public:

    bool ExportToCSV(const std::string &filename);

    bool ImportFromCSV(const std::string &filename);
};
