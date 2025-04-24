#include "views/CustomerView.h"

#include <iostream>

#include "Utils.h"

CustomerView::CustomerView()
{
    std::cout << customerMenu;
    switch (Input::getInput(1, 4))
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
        break;
        case 4:
            return;
    }
}
