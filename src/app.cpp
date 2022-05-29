#include <iostream>
#include <algorithm>

#include <filesystem>

#include "cmd/cmd_util.hpp"

#include "tasks/init_task.hpp"
#include "tasks/clean_task.hpp"

#include "util/vector_util.hpp"

int main(int argc, char** argv) {
    if (argc == 1) {
        std::cerr << "Use the '-h' or the '--help' flag for help." << std::endl;
        return 0;
    }

    auto args = get_range(argc, argv, 1, argc);
    auto cmd = boost::replace_all_copy(args[0], "-", "");
    auto cwd = std::filesystem::current_path().string();

    if (cmd == "init") {
        init_task(cwd);
    }

    else if (cmd == "build") {
        build_task(cwd);
    }

    else if (cmd == "help" || cmd == "h") {
        std::cout << "sjb - The simple java build tool. Version: 1.0.0" << std::endl << std::endl;

        std::cout << "\tinit\tCreates a new sjb project." << std::endl;
        std::cout << "\tbuild\tBuilds the current sjb project." << std::endl;
        std::cout << "\tclean\tDeletes the 'out' folder of the current sjb project." << std::endl;
    }

    else if (cmd == "version") {
        std::cout << "Version: 1.0.0" << std::endl;
    }

    else if (cmd == "clean") {
        clean_task(cwd);
    } 

    else {
        color_println("Invalid command: " + cmd, RED);
    }
}