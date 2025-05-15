#pragma once
#include <string>

/**
 * @brief Import and export csv files
 */
class CSVController
{
public:
    /**
     * @brief Exports all contents of database to file (backup)
     * @param filename filename/path to export to
     * @return true if succeeded
     */
    bool ExportToCSV(const std::string &filename);

    /**
     * @brief Imports contents to database from file
     * @param filename filename/path to import
     * @return true if succeeded
     */
    bool ImportFromCSV(const std::string &filename);
};
