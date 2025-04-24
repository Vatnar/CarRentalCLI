//
// Created by peter on 24/04/2025.
//

#include "views/CarView.h"

#include <iostream>

#include "Utils.h"

CarView::CarView()
{
    std::cout << carMenu;
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
