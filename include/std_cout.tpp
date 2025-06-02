
#include "std_cout.hpp"

/// @brief take the args(from fold expression) to check if it's boolean or not. constexpr to check for bool at complie time
/// @tparam T 
/// @param value 
/// @return 
template<typename T>
std::string StdCout::convertIfBool(const T& value) {
    if constexpr (std::is_same_v<std::decay_t<T>, bool>) {
        return value ? "TRUE" : "FALSE";
    } else {
        std::ostringstream oss;
        oss << value;
        return oss.str();
    }
}

template<typename... Args>
void StdCout::error(const Args&... args) {
    std::ostringstream stream;
    ((stream << this->convertIfBool(args) << " "), ...); // Add a space after each argument
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
    ((stream << this->convertIfBool(args) << " "), ...); // Add a space after each argument
    std::string stream_str = std::move(stream.str());
    // remove the last space
    if(!stream_str.empty() && stream_str.back() == ' ') {
        // std::cout << "removed the last space\n";
        stream_str.pop_back();
    }
    std::cerr << Colour::YELLOW << stream_str << Colour::RESET << std::endl;
}

template<typename... Args>
void StdCout::warnDev(const Args&... args) {
    std::ostringstream stream;
    ((stream << this->convertIfBool(args) << " "), ...); // Add a space after each argument
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
    
    // auto res = std::disjunction_v<std::is_same<std::decay_t<Args>, bool>...>;
    // if(res) {
    //     std::cout << "!!!true\n";
    // } else {
    //     std::cout << "!!!false\n";
    // }

    std::ostringstream stream;
    ((stream << this->convertIfBool(args) << " "), ...); // Add a space after each argument
    std::string stream_str = std::move(stream.str());
    // remove the last space
    if(!stream_str.empty() && stream_str.back() == ' ') {
        // std::cout << "removed the last space\n";
        stream_str.pop_back();
    }
    std::cerr << Colour::WHITE << stream_str << Colour::RESET << std::endl;
}

