#include <fstream>
#include <string>
#include <unordered_map>

#include <boost/algorithm/string.hpp>

#include <vector>

static std::vector<std::string> read_lines(std::string file)
{
    std::ifstream fin(file, std::ios::in);
    std::vector<std::string> v;
    std::string line;

    while (std::getline(fin, line))
    {
        v.push_back(line);
    }

    return v;
}

static std::unordered_map<std::string, std::string> parse(std::string file)
{
    std::vector<std::string> v = read_lines(file);
    std::unordered_map<std::string, std::string> mp;

    for (auto i : v)
    {
        if (!boost::contains(i, ":"))
        {
            continue;
        }
        auto j = i.find(":");

        auto one = i.substr(0, j), two = i.substr(j + 1);
        mp.insert({boost::trim_copy(one), boost::trim_copy(two)});
    }

    return mp;
}