#pragma once
#include <string>

#include "View.h"


class ImportExportView : View {
public:
    ImportExportView();
    void Run() override;
private:
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
    void Import();
    void Export();
};
