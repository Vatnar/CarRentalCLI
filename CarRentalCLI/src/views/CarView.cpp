#include "views/CarView.h"

#include <iostream>

#include "Utils.h"

CarView::CarView()
{
    std::cout << carMenu;
    switch (Input::getInt(1, 4))
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
