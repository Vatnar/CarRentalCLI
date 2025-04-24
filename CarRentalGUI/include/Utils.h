#pragma once
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
