#pragma once
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
    void addCustomer();
    void editCustomer();
    void removeCustomer();
};