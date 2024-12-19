cmake_minimum_required(VERSION 3.30.0)
project(WebGUI VERSION 0.1.0 LANGUAGES CXX)

# Define the source and include directories
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# Add the executable and include source files
add_executable(WebGUI
    main.cpp
    ${SRC_DIR}/sensor.cpp
    ${SRC_DIR}/actuator.cpp    


)

# Include the directories for header files
target_include_directories(WebGUI PRIVATE
    ${INCLUDE_DIR}
)

