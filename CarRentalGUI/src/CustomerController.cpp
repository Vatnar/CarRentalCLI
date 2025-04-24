//
// Created by roem0 on 24.04.2025.
//

#include "CustomerController.h"

void CustomerController::addCustomer(name, tel, birthDate)
{

    CustomerModel newCustomer {-1, name, tel, birthDate};
    newCustomer.id = storage.insert(newCustomer);
}

void CustomerController::editCustomer(name, tel, birthDate)
{

}

void CustomerController::removeCustomer(ID)
{

}