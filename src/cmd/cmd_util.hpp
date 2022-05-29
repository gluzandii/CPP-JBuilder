#include <vector>
#include <unordered_map>

#include <string>

#include "boost/algorithm/string.hpp"

static std::vector<std::string> get_args(int argc, char** argv) {
    std::vector<std::string> v;
    for (auto i = 0; i < argc; i++) {
        auto s = argv[i];
        if (boost::starts_with(s, "-") || boost::contains(s, "=")) {
            continue;
        }

        v.push_back(s);
    }

    return v;
}

static std::vector<std::string> get_flags(int argc, char** argv) {
    std::vector<std::string> v;
    for (auto i = 0; i < argc; i++) {
        auto s = argv[i];
        if (boost::starts_with(s, "-") && !boost::contains(s, "=")) {
            v.push_back(s);
        }
    }

    return v;
}

static std::unordered_map<std::string, std::string> get_kv(int argc, char** argv) {
    std::unordered_map<std::string, std::string> m;
    
    for (auto i = 0; i < argc; i++) {
        auto s = std::string(argv[i]);
        auto j = -1;

        if ((j = s.find("=")) != std::string::npos) {
            m.insert({s.substr(0, j), s.substr(j + 1)});
        }
    }

    return m;
}

static std::string get_command(std::string s) {
    return boost::to_lower_copy(boost::replace_all_copy(s, "-", ""));
}