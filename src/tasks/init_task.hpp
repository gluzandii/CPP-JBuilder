#include <string>
#include <fstream>

#include <util/path_util.hpp>
#include <util/os_util.hpp>

static void init_task(std::string dir) {
    auto file = dir + separator + "jbuild.config.txt";
    auto fout = touch(file);

    fout << "name: " << current_user() << std::endl << "description: NONE" << std::endl;
    fout << "src: " << std::endl << "out: " << std::endl << "package: " << std::endl << std::endl;

    fout.flush();
    fout.close();
}