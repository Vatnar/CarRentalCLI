//
// Created by peter on 24/04/2025.
//

#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <ostream>


class Menu {
public:
    Menu()
    {
        std::string menu = R"MENU(
==================================
        CAR RENTAL SERVICE
==================================
        1. Customer Menu
        2. Car Menu
        3. Rental Menu
        4. Show info...
        5. Exit
==================================
Please enter your choice:
)MENU";

        std::cout << menu << std::endl;
    }
};



#endif //MENU_H
