#include <config/parser.hpp>
#include <filesystem>
#include <string>

#include <cstdlib>

#include "color/color.hpp"

static void build_task(std::string cwd) {
    auto file = cwd + "/jbuild.config.txt";
    if (!std::filesystem::exists(file)) {
        color_println("No jbuild project found in the current directory.", RED);
        return;
    }
    
    auto p = parse(file);
    
    bool canExec = false;
    std::stringstream ss;
    ss << "javac ";

    std::string src = "", out = "";
    if (p.find("src") != p.end() && p.find("out") != p.end()) {
        src = cwd + "/" + p.find("src")->second;
        out = cwd + "/" + p.find("out")->second;

        ss << "-d " << out << " ";

        for (const auto& i : std::filesystem::recursive_directory_iterator(src)) {
            auto p = i.path();
            if (p.extension() == ".java") {
                if (!canExec) {
                    canExec = true;
                }
                ss << p << " ";
            }
        }
    }

    if (canExec) {
        std::system(std::string(ss.str()).c_str());
    } else {
        color_println("No java files to compile in the " + src + " folder.", RED);
    }
}
