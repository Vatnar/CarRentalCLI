#pragma once
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
