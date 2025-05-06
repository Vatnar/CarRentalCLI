#ifndef RENTALVIEW_H
#define RENTALVIEW_H
#include <string>


class RentalView {
public:
    RentalView();
protected:
    std::string rentalMenu = R"MENU(
==================================
            RENTALS
==================================
        1. ADD NEW RENTAL
        2. REMOVE RENTAL
        3. Exit
==================================
Please enter your choice:
)MENU";
};



#endif //RENTALVIEW_H
