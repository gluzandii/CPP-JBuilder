#include <iostream>
#include <algorithm>

#include "cmd/cmd_util.hpp"
#include "color/color.hpp"
#include "util/vector_util.hpp"

int main(int argc, char** argv) {
    if (argc == 1) {
        std::cerr << "Use the '-h' or the '--help' flag for help." << std::endl;
        return 0;
    }

    auto args = get_range(argc, argv, 1, argc);
    auto cmd = get_command(args[0]);

    if (cmd == "init") {

    }

    else if (cmd == "build") {

    }

    else if (cmd == "package") {

    }

    else if (cmd == "clean") {

    } 

    else {
        color_println("Invalid command: " + cmd, RED);
    }
}