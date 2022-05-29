#include <string>

std::string separator = 
#ifdef _WIN32
    "\\";
#else
    "/";
#endif