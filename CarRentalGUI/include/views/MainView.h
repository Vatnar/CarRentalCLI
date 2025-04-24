//
// Created by peter on 24/04/2025.
//

#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <ostream>


class MainView {
public:
    MainView();

protected:
    std::string mainMenu = R"MENU(
==================================
        CAR RENTAL SERVICE
==================================
        1. Customer Menu
        2. Car Menu
        3. Rental Menu
        4. Import/Export
        5. Exit
==================================
Please enter your choice:
)MENU";
};



#endif //MENU_H
