#include "views/CustomerView.h"

#include <iostream>

#include "Utils.h"

CustomerView::CustomerView()
{
    std::cout << customerMenu;
    switch (Input::getInt(1, 4))
    {
        case 1:
            addCustomer(); break;
        case 2:
            editCustomer(); break;
        case 3:
            removeCustomer(); break;
        case 4:
            return;
    }
}

void CustomerView::addCustomer()
{
    std::cout << R"MENU(
==================================
            Add customer
==================================
)MENU" << std::endl;
    std::cout << "Enter name: ";

}
