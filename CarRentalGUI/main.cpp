#include <iostream>
#include <sqlite3.h>
#include <sqlite_orm.h>
#include "storage.h"

int main()
{
    auto storage = init_storage();

    Storage func();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
