cmake_minimum_required(VERSION 3.20)
project(Pixelator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell CMake to use vcpkg toolchain
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "C:/Users/pc planet/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

# Find OpenCV package
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Add executable
add_executable(Pixelator main.cpp)

# Link OpenCV
target_link_libraries(Pixelator ${OpenCV_LIBS})
