#include "views/ImportExportView.h"

#include <iostream>

#include "Utils.h"

ImportExportView::ImportExportView()
{

}

void ImportExportView::Run()
{
    while (true)
    {
        std::cout << importExportMenu;
        switch (Input::getInt(1, 3))
        {
            case 1:
                Import(); break;
            case 2:
                Export(); break;
            default: return;
        }
    }
}

void ImportExportView::Import()
{
    std::cout << "Please enter name of file to import. File must be placed in working directory (same as .exe file):";
    std::string importFile = Input::getString();


    // CSVController.import(importFile);
}
void ImportExportView::Export()
{
    std::cout << "Please enter name of file to export. File will be exported next to .exe:";
    std::string exportFile = Input::getString();


    // CSVController.export(exportFile)
}