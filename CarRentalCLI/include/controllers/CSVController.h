#pragma once
#include <string>

class CSVController
{
public:
    bool ExportToCSV(const std::string &filename);

    bool ImportFromCSV(const std::string &filename);
};
