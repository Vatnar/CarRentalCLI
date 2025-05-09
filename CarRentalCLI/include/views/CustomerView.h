#pragma once
#include <string>

#include "View.h"
#include "controllers/CustomerController.h"


class CustomerView : public View {
public:
    /**
 * @brief Draws a customer menu from which a user can decide to add edit or remove customers
 */
   CustomerView();

    /**
     * @brief Run's the GUI of the view and logic
     */
    void Run() override;

   /**
 * @brief Allows user to search and choose a customerID
 * @return Customer ID chosen by user
 */
   int getCustomerID();
protected:
    /**
 * @brief Prompts the user until a valid name is entered
 * @param name Reference to input name string
 */
    void getName(std::string &name);

    /**
 * @brief Prompts the user until a valid telephone number is entered
 * @param tel Reference to input tel string
 */
    void getTel(std::string &tel);

    /**
 * @brief Prompts the user until a valid email is entered
 * @param email Reference to input email string
 */
    void getEmail(std::string &email);



   /**
* @brief Prompts user for information about a new customer and dispatches it to controller
*/
   void addCustomer();

    /**
     * @brief Searches for customer based on searchphrase and edits the selected customer
     */
    void editCustomer();

    /**
     * @brief Searches for customer based on searchphrase and removes the selected customer
     */
    void removeCustomer();

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
};
