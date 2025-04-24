#include <iostream>
#include <sqlite3.h>
#include "storage.h"
#include "MainMenuView.h"
int main()
{
    auto storage = init_storage();
    MainMenuView menu;

    // std::cout << "Hello, World!" << std::endl;
    return 0;
}
