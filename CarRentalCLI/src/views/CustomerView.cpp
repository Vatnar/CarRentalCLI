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


void CustomerView::getName(std::string &name) {
    std::cout << "Enter name: ";
    name = Input::getString();
    if (name.empty())
    {
        std::cout << "\n Invalid name, Try again";
        getName(name);
    }
}


void CustomerView::getTel(std::string &tel) {
    std::cout << "\n Enter telephone number: ";
    tel = Input::getString(false);
    if (tel.empty())
    {
        std::cout << "\n Invalid telephone number;";
        getTel(tel);
    }
}


void CustomerView::getEmail(std::string &email) {
    std::cout << "\n Enter email: ";
    email = Input::getString(false, '@');
    if (email.empty())
    {
        std::cout << "\n Invalid email, Try again. Format: example@example.org";
        getEmail(email);
    }
}


void CustomerView::addCustomer()
{
    std::cout << R"MENU(
==================================
            Add customer
==================================
)MENU" << std::endl;
    std::string name, tel, email;
    getName(name);
    getTel(tel);
    getEmail(email);

    // if (customerController.addCustomer(name, tel, email))
    {
    }
}
