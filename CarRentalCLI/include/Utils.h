#pragma once
#include <iostream>


class Input
{
public:
    static int getInt(int min, int max)
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
    static std::string getString(bool allowSpaces = true, char includeChar = '\0')
    {
        std::string input;
        std::cin.ignore();
        std::getline(std::cin, input);

        if (!allowSpaces && input.find(' ') != std::string::npos)
        {
            std::cerr << "Spaces are not allowed in the input." << std::endl;
            return "";
        }

        if (includeChar != '\0' && input.find(includeChar) == std::string::npos)
        {
            std::cerr << "The character '" << includeChar << "' must be included in the input." << std::endl;
            return "";
        }

        return input;
    }
};
