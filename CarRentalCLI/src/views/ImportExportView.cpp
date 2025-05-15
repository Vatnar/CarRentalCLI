#include "views/ImportExportView.h"

#include <iostream>
#include <string>

#include "Utils.h"
#include "controllers/CSVController.h"

ImportExportView::ImportExportView()
{}

void ImportExportView::Run()
{
    while (true)
    {
        std::cout << importExportMenu;
        switch (Input::GetInt(1, 3))
        {
            case 1: importcsv();
                break;
            case 2: exportcsv();
                break;
            default: return;
        }
    }
}

void ImportExportView::importcsv()
{
    std::cout <<
            "Please enter name of file to import. File must be placed in working directory (same as .exe file):";
    std::string importFile = Input::GetString();


    csvController.ImportFromCSV(importFile);
}

void ImportExportView::exportcsv()
{
    std::cout <<
            "Please enter name of file to export. File will be exported next to .exe:";
    std::string exportFile = Input::GetString();

    csvController.ExportToCSV(exportFile);
}
