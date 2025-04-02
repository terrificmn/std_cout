cmake_minimum_required(VERSION 3.10)
project(example_std_cout)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(std_cout REQUIRED)
add_executable(example_std_cout src/main.cpp)
target_link_libraries(example_std_cout PRIVATE ${STD_COUT_LIBRARIES})
target_include_directories(example_std_cout PRIVATE ${STD_COUT_INCLUDE_DIR})
