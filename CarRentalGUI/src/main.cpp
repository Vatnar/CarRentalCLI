#include <iostream>
#include <sqlite3.h>
#include "storage.h"
#include "views/MainView.h"
int main()
{
    auto storage = init_storage();
    MainView menu;

    // std::cout << "Hello, World!" << std::endl;
    return 0;
}
