//
// Created by peter on 24/04/2025.
//

#ifndef CARVIEW_H
#define CARVIEW_H
#include <string>


class CarView {
public:
    CarView();
protected:
    std::string carMenu = R"MENU(
==================================
              CARS
==================================
        1. ADD CAR
        2. EDIT CAR
        3. REMOVE CAR
        4. Exit
==================================
Please enter your choice:
)MENU";
};



#endif //CARVIEW_H
