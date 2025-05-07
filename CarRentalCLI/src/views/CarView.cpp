#include "views/CarView.h"

#include <iostream>

#include "Utils.h"

CarView::CarView()
{
    std::cout << carMenu;
    switch (Input::getInt(1, 4))
    {
        case 1:
            addCar(); break;
        case 2:
            editCar(); break;
        case 3:
            removeCar(); break;
        case 4:
            return;
    }
}

int CarView::getCarID() {}

void CarView::addCar() {}
void CarView::editCar() {}
void CarView::removeCar() {}
