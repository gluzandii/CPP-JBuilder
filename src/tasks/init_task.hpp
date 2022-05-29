#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#include <Lmcons.h>
#else
#include <unistd.h>
#endif

static std::string current_user() {
#ifdef _WIN32
    char username[UNLEN+1];
    DWORD username_len = UNLEN+1;
    GetUserName(username, &username_len);

    return std::string(username);
#else
    return getlogin();
#endif
} 

static std::ofstream touch(std::string file) {
    auto p = std::filesystem::path(file).parent_path();

    std::filesystem::create_directories(p);
    return std::ofstream(file, std::ios::out);
}

static void init_task(std::string dir) {
    auto file = dir + "/sjb.config.txt";
    if (std::filesystem::exists(file)) {
        std::cerr << "Current directory already has a jbuild project." << std::endl;
        return;
    }

    auto fout = touch(file);

    fout << "name: " << current_user() << std::endl << "description: NONE" << std::endl;
    fout << "src: " << std::endl << "out: " << std::endl << std::endl;

    fout.flush();
    fout.close();
}