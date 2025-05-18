#include <filesystem>
#include <iostream>
#include <sqlite3.h>

#include "storage.h"
#include "controllers/CarController.h"
#include "controllers/CustomerController.h"
#include "views/MainView.h"

void sampleImport()
{
    std::filesystem::remove("CarRental.sqlite");

    storage.sync_schema();
    CustomerController customerController;
    CarController      carController;
    RentalController   rentalController;

    for (int i = 1; i <= 30; ++i) {
        customerController.AddCustomer(
            "Customer" + std::to_string(i),
            "Tel" + std::to_string(1000 + i),
            "customer" + std::to_string(i) + "@example.com"
        );
    }

    for (int i = 0; i < 25; ++i) {
        std::string plate = "AB";
        plate += (i < 10) ? "0000" : "000";
        plate += std::to_string(i);

        std::string brand = "Brand" + std::to_string((i % 5) + 1);
        std::string model = "Model" + std::to_string((i % 7) + 1);
        carController.AddCar(plate, brand, model);
    }

    int rentalId = 1;

    // Generate renadom rentals
    for (int custId = 1; custId <= 30; ++custId) {
        for (int carId = 1; carId <= 10; ++carId) {
            int startMonth = ((custId + carId) % 12) + 1;
            int startDay = ((custId * carId) % 20) + 1;
            int duration = ((custId + carId) % 13) + 3;

            char startDate[11];
            char endDate[11];
            snprintf(startDate, sizeof(startDate), "2024-%02d-%02d", startMonth, startDay);
            snprintf(endDate, sizeof(endDate), "2024-%02d-%02d", startMonth, startDay + duration);

            rentalController.RentCar(custId, carId, startDate, endDate);

            if (++rentalId > 40)
                break;
        }
        if (rentalId > 40)
            break;
    }

    std::cout << "Added extended sample data: 30 customers, 25 cars, 40 rentals." << std::endl;
}


int main()
{
    // sampleImport();
    storage.sync_schema();
    MainView menu;
    menu.Run();

    return 0;
}

