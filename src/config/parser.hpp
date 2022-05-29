#include <fstream>
#include <string>
#include <unordered_map>

#include <util/os_util.hpp>
#include <boost/algorithm/string.hpp>

static std::unordered_map<std::string, std::string> parse(std::string file) {
    std::vector<std::string> v = read_lines(file);
    std::unordered_map<std::string, std::string> mp;

    for (auto i : v) {
        if (!boost::contains(i, ":")) {
            continue;
        }
        auto j = i.find(":");

        auto one = i.substr(0, j), two = i.substr(j + 1);
        mp.insert({one, two});
    }

    return mp;
}