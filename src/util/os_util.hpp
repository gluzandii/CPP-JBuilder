#include <unistd.h>
#include <string>
#include <filesystem>

#ifdef _WIN32
#include <windows.h>
#include <Lmcons.h>
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