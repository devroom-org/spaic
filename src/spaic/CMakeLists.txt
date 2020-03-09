cmake_minimum_required(VERSION 3.12.0)
project(Spaic)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-fconcepts)

include_directories("../../include/")
file(GLOB_RECURSE SOURCE_LIST "./*.cpp")
list(FILTER SOURCE_LIST EXCLUDE REGEX "CMakeCXXCompilerId.cpp$")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../bin")

add_library(${PROJECT_NAME} STATIC ${SOURCE_LIST})
