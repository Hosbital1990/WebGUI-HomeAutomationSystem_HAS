# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.20)  # Updated to 3.20 for better C++20 support

# Define the project name, version, and language
project(WebGUI VERSION 1.0.0 LANGUAGES CXX)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # Ensure the compiler enforces the standard
set(CMAKE_CXX_EXTENSIONS OFF)       # Disable compiler-specific extensions

# Define the source and include directories
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# Automatically add all .cpp files in the src directory
file(GLOB_RECURSE SRC_FILES ${SRC_DIR}/*.cpp)

# Add the executable and include source files
add_executable(WebGUI
    main.cpp
    ${SRC_FILES}
)

# Include the directories for header files
target_include_directories(WebGUI PRIVATE
    ${INCLUDE_DIR}
)

# Find and include OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(WebGUI ${OpenCV_LIBS})

# Find and include SQLite3
find_package(SQLite3 REQUIRED)
include_directories(${SQLite3_INCLUDE_DIRS})
target_link_libraries(WebGUI ${SQLite3_LIBRARIES})

# Link ncurses library
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(WebGUI ${CURSES_LIBRARIES})

# Enable modern compiler warnings (optional but recommended)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(WebGUI PRIVATE -Wall -Wextra -pedantic)
endif()