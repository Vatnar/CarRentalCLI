#include "views/RentalView.h"

#include <iostream>

#include "Utils.h"

RentalView::RentalView() {
    std::cout << rentalMenu;
    switch (Input::getInput(1, 4))
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            return;
    }
}
