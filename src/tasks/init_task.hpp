#include <string>
#include <fstream>

#include <util/path_util.hpp>

static void init_task(std::string dir) {
    std::string file = dir + separator + "jbuild.config.txt";

    std::ofstream fout(dir, std::ios::out);

    fout << "src: " << std::endl << "out: " << std::endl << "package: " << std::endl << std::endl;
}