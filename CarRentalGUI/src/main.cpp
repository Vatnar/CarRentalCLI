#include <iostream>
#include <sqlite3.h>
#include "storage.h"
#include "Menu.h"
int main()
{
    Menu menu;
    auto storage = init_storage();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
