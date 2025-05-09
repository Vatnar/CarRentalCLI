#include "views/MainView.h"
#include "Utils.h"

MainView::MainView() = default;

void MainView::Run()
{
    while (true)
    {
        std::cout << mainMenu;

        switch (Input::getInt(1, 6))
        {
            case 0: // not allowed
                break;
            case 1:
            {customerView.Run(); break;}
            case 2:
            {carView.Run(); break;}
            case 3:
            {rentalView.Run(); break;}
            case 4:
            {StatisticsView statisticsView; break;}
            case 5:
            {ImportExportView importExportView; break;}
            default:
                std::cout << "Exiting program...\n";exit(0);
        }
        std::cout << std::endl;
    }
}
