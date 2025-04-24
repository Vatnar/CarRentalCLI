//
// Created by peter on 24/04/2025.
//

#ifndef CUSTOMERVIEW_H
#define CUSTOMERVIEW_H
#include <string>


class CustomerView {
public:
    CustomerView();
protected:
    std::string customerMenu = R"MENU(
==================================
            CUSTOMERS
==================================
        1. ADD CUSTOMER
        2. EDIT CUSTOMER
        3. REMOVE CUSTOMER
        4. Exit
==================================
Please enter your choice:
)MENU";
};



#endif //CUSTOMERVIEW_H
