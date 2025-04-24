//
// Created by peter on 24/04/2025.
//

#ifndef UTILS_H
#define UTILS_H
#include <iostream>


class Input
{
public:
    static int getInput(int min, int max)
    {
        int input;
        std::cin.clear();
        std::cin >> input;
        if (input < min || input > max)
        {
            std::cerr << "Invalid input." << std::endl;
            return 0;
        }

        return input;
    }
};
#endif //UTILS_H
