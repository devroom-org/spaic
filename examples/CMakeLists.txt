cmake_minimum_required(VERSION 3.8.0)
project(SpaicExample)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories("../include/")
file(GLOB_RECURSE SOURCE_LIST "./*.cpp")
list(FILTER SOURCE_LIST EXCLUDE REGEX "CMakeCXXCompilerId.cpp$")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin")

foreach( source ${SOURCE_LIST} )
    string(REPLACE ".cpp" "" name ${source} )
    string(REGEX REPLACE ".+/" "" name ${name} )
    add_executable( ${name} ${source} )
    target_link_libraries(${name}
    PRIVATE
        Spaic
        SpaicCSS
    )
endforeach( source ${SOURCE_LIST} )