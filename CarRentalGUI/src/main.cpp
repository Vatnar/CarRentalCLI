#include <iostream>
#include <sqlite3.h>
#include "storage.h"

int main()
{
    auto storage = init_storage();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
