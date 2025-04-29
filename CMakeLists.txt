cmake_minimum_required(VERSION 3.10)
project(ExampleCallApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include necessary directories
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/peInterface/interface)

# Gather .cpp files
file(GLOB ROOT_SOURCES "${CMAKE_SOURCE_DIR}/*.cpp")
file(GLOB PE_INTERFACE_SOURCES "${CMAKE_SOURCE_DIR}/peInterface/*.cpp")

# Main file
set(MAIN_SRC "${CMAKE_SOURCE_DIR}/exampleCall.cpp")

# Create executable
add_executable(ExampleCallApp ${MAIN_SRC} ${ROOT_SOURCES} ${PE_INTERFACE_SOURCES})