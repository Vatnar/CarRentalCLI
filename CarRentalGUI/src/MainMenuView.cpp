//
// Created by peter on 24/04/2025.
//
#include "MainMenuView.h"
#include "Utils.h"


MainMenuView::MainMenuView() {

    std::cout << mainMenu;

    switch (Input::getInput(1, 5))
    {
        case 0: // not allowed
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            std::cout << "Exiting program...\n";
            exit(0);
    }
    std::cout << std::endl;

}
