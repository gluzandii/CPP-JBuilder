#include <config/parser.hpp>
#include <filesystem>
#include <string>

#include <cstdlib>

#include "color/color.hpp"

static void build_task(std::string cwd)
{
    auto file = cwd + "/sjb.config.txt";
    if (!std::filesystem::exists(file))
    {
        color_println("No jbuild project found in the current directory.", RED);
        return;
    }

    auto p = parse(file);

    bool canExec = false;
    std::stringstream ss;
    ss << "javac ";

    std::string src = "", out = "";
    if (p.find("src") != p.end() && p.find("out") != p.end())
    {
        src = cwd + "/" + p.find("src")->second;
        out = cwd + "/" + p.find("out")->second;

        ss << "-d \"" << out << "\" ";

        if (std::filesystem::exists(src) && std::filesystem::is_directory(src))
        {
            for (const auto &i : std::filesystem::recursive_directory_iterator(src))
            {
                auto p = i.path();
                if (p.extension() == ".java")
                {
                    if (!canExec)
                    {
                        canExec = true;
                    }
                    ss << "\"" << p << "\" ";
                }
            }
        }
    }

    if (p.find("include") != p.end())
    {
        auto include = cwd + "/" + p.find("include")->second;
        auto s =
#ifdef _WIN32
            ";";
#else
            ":";
#endif

        if (std::filesystem::exists(include) && std::filesystem::is_directory(include))
        {
            for (const auto &i : std::filesystem::recursive_directory_iterator(include))
            {
                auto p = i.path();
                if (p.extension() == ".jar")
                {
                    ss << "-cp \"" << p << s << p.parent_path() << "/*"
                       << "\"";
                    break;
                }
            }
        }
    }

    if (canExec)
    {
        std::system(std::string(ss.str()).c_str());
    }
    else
    {
        color_println("No java files to compile in the " + src + " folder.", RED);
    }
}
