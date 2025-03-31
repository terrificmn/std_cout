
#include "std_cout.hpp"

template<typename... Args>
void StdCout::error(const Args&... args) {
    std::ostringstream stream;
    ((stream << args << " "), ...); // Add a space after each argument
    std::string stream_str = std::move(stream.str());
    // remove the last space
    if(!stream_str.empty() && stream_str.back() == ' ') {
        // std::cout << "removed the last space\n";
        stream_str.pop_back();
    }
    std::cerr << Colour::RED << stream_str << Colour::RESET << std::endl;
}

template<typename... Args>
void StdCout::warn(const Args&... args) {
    std::ostringstream stream;
    ((stream << args << " "), ...); // Add a space after each argument
    std::string stream_str = std::move(stream.str());
    // remove the last space
    if(!stream_str.empty() && stream_str.back() == ' ') {
        // std::cout << "removed the last space\n";
        stream_str.pop_back();
    }
    std::cerr << Colour::GREEN << stream_str << Colour::RESET << std::endl;
}

template<typename... Args>
void StdCout::info(const Args&... args) {
    std::ostringstream stream;
    ((stream << args << " "), ...); // Add a space after each argument
    std::string stream_str = std::move(stream.str());
    // remove the last space
    if(!stream_str.empty() && stream_str.back() == ' ') {
        // std::cout << "removed the last space\n";
        stream_str.pop_back();
    }
    std::cerr << Colour::WHITE << stream_str << Colour::RESET << std::endl;
}

