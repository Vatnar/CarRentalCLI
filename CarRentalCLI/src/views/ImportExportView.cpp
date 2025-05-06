#include "views/ImportExportView.h"

#include <iostream>

#include "Utils.h"

ImportExportView::ImportExportView()
{
    std::cout << importExportMenu;
    switch (Input::getInt(1, 4))
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            return;
    }
}
