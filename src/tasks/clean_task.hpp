#include <filesystem>

#include "build_task.hpp"

static void clean_task(std::string cwd)
{
    auto file = cwd + "/sjb.config.txt";
    if (!std::filesystem::exists(file))
    {
        color_println("No jbuild project found in the current directory.", RED);
        return;
    }

    auto p = parse(file);
    auto out_c = p.find("out");

    if (out_c != p.end()) {
        auto out = out_c->second;
        std::filesystem::remove_all(cwd + "/" + out);
    }
}