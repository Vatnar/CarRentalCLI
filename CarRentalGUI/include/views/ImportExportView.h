//
// Created by peter on 24/04/2025.
//

#ifndef IMPORTEXPORTVIEW_H
#define IMPORTEXPORTVIEW_H
#include <string>


class ImportExportView {
public:
    ImportExportView();
protected:
    std::string importExportMenu = R"MENU(
==================================
          IMPORT/EXPORT
==================================
        1. IMPORT
        2. EXPORT
        3. Exit
==================================
Please enter your choice:
)MENU";
};



#endif //IMPORTEXPORTVIEW_H
