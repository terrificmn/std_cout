#include "std_cout.hpp"

template<typename T>
void StdCout::error(const T& msg) {
    if(typeid(T) == typeid(bool)) {
        std::cerr << Colour::RED << std::boolalpha << msg << Colour::RESET << std::endl;
    } else {
        std::cerr << Colour::RED << msg << Colour::RESET << std::endl;
    }
}
/// overload for char
void StdCout::error(const char* msg) {
    std::cerr << Colour::RED << msg << Colour::RESET << std::endl;
}


template<typename T>
void StdCout::warn(const T& msg) {
    if(typeid(T) == typeid(bool)) {
        std::cerr << Colour::YELLOW << std::boolalpha << msg << Colour::RESET << std::endl;
    } else {
        std::cerr << Colour::YELLOW << msg << Colour::RESET << std::endl;
    }
}
/// overload for char
void StdCout::warn(const char* msg) {
    std::cerr << Colour::YELLOW << msg << Colour::RESET << std::endl;
}


template<typename T>
void StdCout::warnDev(const T& msg) {
    if(typeid(T) == typeid(bool)) {
        std::cerr << Colour::GREEN << std::boolalpha << msg << Colour::RESET << std::endl;
    } else {
        std::cerr << Colour::GREEN << msg << Colour::RESET << std::endl;
    }
}
/// overload for char
void StdCout::warnDev(const char* msg) {
    std::cerr << Colour::GREEN << msg << Colour::RESET << std::endl;
}


/// @brief This prints out faster than error, warn using std::cerr
/// @tparam T 
/// @param msg 
template<typename T>
void StdCout::info(const T& msg) {
    if(typeid(T) == typeid(bool)) {
        std::cout << Colour::WHITE << std::boolalpha << msg << Colour::RESET << std::endl;        
    } else {
        std::cout << Colour::WHITE << msg << Colour::RESET << std::endl;
    }
}
/// overload for char
void StdCout::info(const char* msg) {
    std::cout << Colour::WHITE << msg << Colour::RESET << std::endl;
}


/// possible available types for parameter are defined. Only these type can be passed through the each function, including const char*. 
// Explicit Instantiation
template void StdCout::error(const std::string& msg);
template void StdCout::error(const double& msg);
template void StdCout::error(const float& msg);
template void StdCout::error(const int& msg);
template void StdCout::error(const bool& msg);

template void StdCout::warn(const std::string& msg);
template void StdCout::warn(const double& msg);
template void StdCout::warn(const float& msg);
template void StdCout::warn(const int& msg);
template void StdCout::warn(const bool& msg);

template void StdCout::warnDev(const std::string& msg);
template void StdCout::warnDev(const double& msg);
template void StdCout::warnDev(const float& msg);
template void StdCout::warnDev(const int& msg);
template void StdCout::warnDev(const bool& msg);

template void StdCout::info(const std::string& msg);
template void StdCout::info(const double& msg);
template void StdCout::info(const float& msg);
template void StdCout::info(const int& msg);
template void StdCout::info(const bool& msg);

