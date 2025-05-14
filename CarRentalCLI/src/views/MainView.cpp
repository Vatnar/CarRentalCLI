#include "views/MainView.h"
#include "Utils.h"

MainView::MainView() : rentalView(customerView, carView){};

void MainView::Run()
{
    while (true)
    {
        std::cout << mainMenu;
        int choice = Input::getInt(1, 6);

        switch (choice)
        {
            case 0: // not allowed
                break;
            case 1:
            customerView.Run(); break;
            case 2:
            carView.Run(); break;
            case 3:
            rentalView.Run(); break;
            case 4:
            statisticsView.Run(); break;
            case 5:
            importExportView.Run(); break;
            case 6:
                std::cout << "Exiting program...\n"; exit(0);
            default:
                break;
        }
        std::cout << std::endl;
    }
}
