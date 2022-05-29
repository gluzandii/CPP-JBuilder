#include <vector>
#include <string>

static std::vector<std::string> get_range(int argc, char** argv, int start, int length) {
    std::vector<std::string> v;
    while (start < argc && start < length) {
        v.push_back(argv[start++]);
    }

    return v;
}