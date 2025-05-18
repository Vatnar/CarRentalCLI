#pragma once
#include <string>

#include "View.h"
#include "controllers/CarController.h"


class CarView : public View
{
public:
    CarView();

    /**
     * @brief Run's the GUI of the view and logic
     */
    void Run() override;

    /**
     * Allows user to search and choose a customerID
     * @return Car ID chosen by user
     */
    int getCarID();

private:
    /**
     * Checks wether or not input regNo is valid
     * @param s string to check
     * @return true if regNo is valid
     */
    bool isValidReg(const std::string &s);

    /**
     * @brief Prompts the user until a valid registration number is entered
     * @param reg Reference to input registration number string
     */
    void getReg(std::string &reg);

    /**
     * @brief Prompts the user until a valid brand name is entered
     * @param brand Reference to input brand string
     */
    void getBrand(std::string &brand);

    /**
     * @brief Prompts the user until a valid model name is entered
     * @param model Reference to input model string
     */
    void getModel(std::string &model);


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

    void listCars();


    std::string   carMenu = R"MENU(
==================================
              CARS
==================================
        1. ADD CAR
        2. EDIT CAR
        3. REMOVE CAR
        4. LIST CARS
        5. RETURN TO MENU
==================================
Please enter your choice:
)MENU";
    CarController carController;
};
