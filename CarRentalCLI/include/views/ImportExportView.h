#pragma once
#include <string>

#include "View.h"
#include "controllers/CSVController.h"


class ImportExportView : View
{
public:
    ImportExportView();

    void Run() override;

private:
    void importcsv();

    void exportcsv();

    CSVController csvController;

    std::string importExportMenu = R"MENU(
==================================
          IMPORT/EXPORT
==================================
        1. IMPORT
        2. EXPORT
        3. RETURN TO MENU
==================================
Please enter your choice:
)MENU";
};
