#pragma once
#include <iostream>
#include <conio.h>
/**
* @brief Provides static methods to get user input
* All function within class provides error handling
*/
class Input
{
public:

    /**
    * @brief Handles integer input from user.
    *
    * @param min The minimum allowed value.
    * @param max The maximum allowed value.
    * @return A valid integer input from the user.
    */
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

    /**
     * @brief Prompts the user to enter a string.
     *
     * @param allowSpaces Whether spaces are allowed in the string (default is true).
     * @param includeChar A character that must be included in the string (default is '\0', meaning no specific character required).
     * @return A valid string input from the user.
     */
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
