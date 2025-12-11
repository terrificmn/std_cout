cmake_minimum_required(VERSION 3.10)
project(std_cout VERSION 1.1.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create a shared library
add_library(std_cout SHARED 
    src/std_cout.cpp
)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

# Define installation paths
install(TARGETS std_cout EXPORT std_coutTargets
    LIBRARY DESTINATION lib/${PROJECT_NAME}
    ARCHIVE DESTINATION lib/${PROJECT_NAME}
    RUNTIME DESTINATION bin/${PROJECT_NAME}
    INCLUDES DESTINATION include/${PROJECT_NAME} ## 설치되지는 않음
)

## tpp 파일까지 포함하므로 include 전체를 설치하는 것도 좋음
install(DIRECTORY include/ DESTINATION include/${PROJECT_NAME})


###################################################################3
###################################################################
###################################################################3
# Generate CMake package files
install(EXPORT std_coutTargets
    FILE std_coutTargets.cmake
    NAMESPACE std_cout::
    DESTINATION lib/cmake/std_cout
)
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/std_coutConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

### 같은 프로젝트 경로에 std_coutConfig.cmake.in 를 만들어 준다. std_coutConfig.cmake.in 파일 참고
configure_file(std_coutConfig.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/std_coutConfig.cmake @ONLY)
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/std_coutConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/std_coutConfigVersion.cmake"
    DESTINATION lib/cmake/std_cout
)
## 다른 패키지에서 find_package()로 찾을 때 {my_pkg}Config.cmake 를 참조하게 된다.