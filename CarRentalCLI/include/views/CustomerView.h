#pragma once
#include <string>

#include "controllers/CustomerController.h"


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
    CustomerController customerController;
    void addCustomer();
    void editCustomer();
    void removeCustomer();
};
