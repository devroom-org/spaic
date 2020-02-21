cmake_minimum_required(VERSION 3.8.0)
project(SpaicRoot)

add_subdirectory(./src/spaic)
add_subdirectory(./src/spaic-css)
add_subdirectory(./src/spaic-dom)
add_subdirectory(./src/spaic-dui)

add_subdirectory(./examples)