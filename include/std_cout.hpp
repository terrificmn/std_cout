#ifndef STD_COUT_HPP
#define STD_COUT_HPP
#include <iostream>
#include <sstream>
namespace Colour {
    constexpr const char* WHITE = "\033[37m";
    constexpr const char* YELLOW = "\033[33m";
    constexpr const char* GREEN = "\033[32m";
    constexpr const char* RED = "\033[1;31m"; // in bold
    constexpr const char* CYAN = "\033[36m";
    constexpr const char* RESET = "\033[0m";
}
class __attribute__((visibility("default"))) StdCout {
public:
    StdCout() = default;
    template<typename T>
    std::string convertIfBool(const T& value);
    
    template<typename T>
    void error(const T& msg);
    void error(const char* msg); // for overload
    template<typename... Args>
    void error(const Args&... args);

    template<typename T>
    void warn(const T& msg);
    void warn(const char* msg); // for overload
    template<typename... Args>
    void warn(const Args&... args);

    template<typename T>
    void warnDev(const T& msg);
    void warnDev(const char* msg); // for overload
    template<typename... Args>
    void warnDev(const Args&... args);

    template<typename T>
    void info(const T& msg);
    void info(const char* msg); // for overload
    template<typename... Args>
    void info(const Args&... args);
};
#include "std_cout.tpp" /// FYI: include order is important. because Colour the above is used in template functions
#endif //STD_COUT_HPP