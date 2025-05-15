#pragma once
#include <iostream>
#include <conio.h>
#include <limits>
#include <chrono>

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
    static int GetInt(int min, int max)
    {
        int input;

        while (true)
        {
            std::cout << "Enter a number (" << min << " - " << max << "): ";

            if (std::cin >> input)
            {
                if (input >= min && input <= max)
                {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    return input;
                }
                else
                {
                    std::cerr << "Invalid input. Please enter a number between "
                              << min << " and " << max << ".\n";
                }
            }
            else
            {
                std::cerr << "Invalid input (not a number).\n";
                std::cin.clear(); // Clear error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }


    /**
     * @brief Prompts the user to enter a string.
     *
     * @param allowSpaces Whether spaces are allowed in the string (default is true).
     * @param includeChar A character that must be included in the string (default is '\0', meaning no specific character required).
     * @return A valid string input from the user.
     */
    static std::string GetString(bool allowSpaces = true, char includeChar = '\0')
    {
        std::string input;

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


class Time {
public:
    /**
     * @brief Returns the current time formatted as YYYY-MM-DD hh-mm.
     *
     * @return Formatted current date and time as a string.
     */
    static std::string GetCurrentTime() {
        // Get current time
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);

        // Convert to local time
        std::tm localTime = *std::localtime(&now_c);

        // Formatting to YYYY-MM-DD hh-mm
        std::ostringstream currentDateStream;
        currentDateStream << std::put_time(&localTime, "%Y-%m-%d %H-%M");
        return currentDateStream.str();
    }
};
