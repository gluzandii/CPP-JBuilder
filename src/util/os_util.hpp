#include <unistd.h>
#include <string>
#include <filesystem>
#include <vector>

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

static std::vector<std::string> read_lines(std::string file) {
    std::ifstream fin(file, std::ios::in);
    std::vector<std::string> v;
    std::string line;

    while (std::getline(fin, line)) {
        v.push_back(line);
    }

    return v;
}