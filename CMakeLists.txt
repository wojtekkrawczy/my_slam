cmake_minimum_required(VERSION 3.22)
project(my_slam VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Eigen3 REQUIRED NO_MODULE)
find_package(Sophus REQUIRED)
find_package(OpenCV REQUIRED)
find_package(GTest REQUIRED)

add_library(my_slam_core
    core/src/placeholder.cpp
)
target_include_directories(my_slam_core PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/core/include>
)
target_link_libraries(my_slam_core PUBLIC
    Eigen3::Eigen
    Sophus::Sophus
    ${OpenCV_LIBS}
)
target_compile_options(my_slam_core PRIVATE -Wall -Wextra -Wpedantic)

enable_testing()
add_executable(test_sanity tests/test_sanity.cpp)
target_link_libraries(test_sanity PRIVATE my_slam_core GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_sanity)