#include "views/CustomerView.h"

#include <iostream>

#include "Utils.h"


CustomerView::CustomerView() = default;

void CustomerView::Run()
{
    while (true)
    {
        std::cout << customerMenu;
        switch (Input::getInt(1, 5))
        {
            case 1:
                addCustomer(); break;
            case 2:
                editCustomer(); break;
            case 3:
                removeCustomer(); break;
            case 4:
                listCustomers(); break;
            default:
                return;
        }
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
        return getEmail(email);
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

    customerController.addCustomer(name, tel, email);
}



void CustomerView::editCustomer() {
    std::cout << R"MENU(
==================================
            Edit customer
==================================
    )MENU" << std::endl;

    int customerID = getCustomerID();
    std::string name, tel, email;
     const auto customer = customerController.getCustomerByID(customerID);
    if ( customer == std::nullopt)
    {
        std::cout << "INTERNAL FAILURE " << __FILE__ << __LINE__ << std::endl;
    }
    std::cout << customer->name << "\t\t" << customer->tel << "\t\t" << customer->email << std::endl;

    getName(name);
    getTel(tel);
    getEmail(email);

    customerController.editCustomer(customerID, name, tel, email);
}

void CustomerView::removeCustomer()
{
    std::cout << R"MENU(
==================================
            Remove customer
==================================
    )MENU" << std::endl;

    int customerID = getCustomerID();

    customerController.removeCustomer(customerID);
}

void CustomerView::listCustomers() {
    std::vector<CustomerModel> customers = customerController.searchCustomer("");
    if (customers.empty())
    {
        std::cout << " No customers in system\n";
        return;
    }
    std::cout << customers.size() << " Customers" << std::endl;
    int index = 0;
    for (const auto& customer : customers)
    {
        std::cout << index++ << ".\t " << customer.name << "\t\t" << customer.tel << "\t\t" << customer.email << std::endl;
    }
}


int CustomerView::getCustomerID() {
    std::string searchString;
    std::cout << "Input search string. Press Enter to search. Press enter without search string to list all\n ";
    searchString = Input::getString();
    std::cout << searchString << std::endl;

    std::vector<CustomerModel> customers = customerController.searchCustomer(searchString);
    if (customers.empty())
    {
        std::cout << "\n Customer not found. Try again" << std::endl;
        return getCustomerID();
    }
    std::cout << "Found " << customers.size() << " out of " << customerController.countCustomers() << std::endl;
    int index = 0;
    for (const auto& customer : customers)
    {
        std::cout << index++ << ".\t " << customer.name << "\t\t" << customer.tel << "\t\t" << customer.email << std::endl;
    }
    std::cout << "Enter number to choose: ";
    auto indexCustomer = Input::getInt(0, customers.size()-1); // -1 cuz of 0 index
    return customers[indexCustomer].customerID;
}
