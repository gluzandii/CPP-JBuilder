#include <iostream>
#include <algorithm>

#include <filesystem>

#include "cmd/cmd_util.hpp"

#include "color/color.hpp"

#include "tasks/init_task.hpp"

#include "util/vector_util.hpp"

int main(int argc, char** argv) {
    if (argc == 1) {
        std::cerr << "Use the '-h' or the '--help' flag for help." << std::endl;
        return 0;
    }

    auto args = get_range(argc, argv, 1, argc);
    auto cmd = args[0];
    auto cwd = std::filesystem::current_path().string();

    if (cmd == "init") {
        init_task(cwd);
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