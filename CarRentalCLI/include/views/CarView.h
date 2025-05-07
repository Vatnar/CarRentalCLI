//
// Created by peter on 24/04/2025.
//

#ifndef CARVIEW_H
#define CARVIEW_H
#include <string>

#include "controllers/CarController.h"


class CarView {
public:
    CarView();

    bool isValid(const std::string &s);

protected:

    /**
     * @brief Prompts the user until a valid registration number is entered
     * @param reg Reference to input registration number string
     */
    void getReg(std::string& reg);

    /**
     * @brief Prompts the user until a valid brand name is entered
     * @param brand Reference to input brand string
     */
    void getBrand(std::string& brand);

    /**
     * @brief Prompts the user until a valid model name is entered
     * @param model Reference to input model string
     */
    void getModel(std::string& model);

    /**
     * Allows user to search and choose a customerID
     * @return Car ID chosen by user
     */
    int getCarID();

    /**
     * @brief Prompts the user for information about a new customer and dispatches it to controller
     */
    void addCar();

    /**
     * Searches for car based on searchphrase and edits the selected car
     */
    void editCar();

    /**
     * Searches for car based on searchphrase and removes the selected car
     */
    void removeCar();



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
    CarController carController;
};


#endif //CARVIEW_H
