#include <iostream>
#include <string>

#include "color_enum.hpp"

struct COLOR_PRINT
{
    std::string RESET = "\033[0m";
    std::string RED = "\033[0;31m";    // RED
    std::string GREEN = "\033[0;32m";  // GREEN
    std::string YELLOW = "\033[0;33m"; // YELLOW
    std::string BLUE = "\033[0;34m";   // BLUE
    std::string PURPLE = "\033[0;35m"; // PURPLE
    std::string CYAN = "\033[0;36m";   // CYAN
};

struct COLOR_PRINT c;

static void color_print(std::string msg, COLOR clr)
{
    switch (clr)
    {
    case RED:
        std::cout << c.RED;
        break;
    case BLUE:
        std::cout << c.BLUE;
        break;
    case GREEN:
        std::cout << c.GREEN;
        break;
    case YELLOW:
        std::cout << c.YELLOW;
        break;
    case PURPLE:
        std::cout << c.PURPLE;
        break;
    case CYAN:
        std::cout << c.CYAN;
        break;
    }

    std::cout << msg << c.RESET;
}

static void color_println(std::string msg, COLOR clr)
{
    color_print(msg, clr);
    std::cout << std::endl;
}