cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project("Anna's Examples")

# write all executables into this directory:
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_subdirectory("Junior Problems 2020 Test/Question 1")
add_subdirectory("Junior Problems 2020 Test/Question 3")
add_subdirectory("Junior Problems 2020 Test/Question 4")

