cmake_minimum_required(VERSION 3.10)
project(PC2_BracketSolver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(BracketSolver STATIC
    src/BracketSolver.cpp
)

target_include_directories(BracketSolver PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(main src/main.cpp)

target_link_libraries(main PRIVATE BracketSolver)

# Demos
add_executable(demo_brackets_optimized demos/demo_brackets_optimized.cpp)

target_link_libraries(demo_brackets_optimized PRIVATE BracketSolver)

add_executable(demo_brackets_nonoptimized demos/demo_brackets_nonoptimized.cpp)

target_link_libraries(demo_brackets_nonoptimized PRIVATE BracketSolver)

add_executable(demo_brackets_comparison demos/demo_brackets_comparison.cpp)

target_link_libraries(demo_brackets_comparison PRIVATE BracketSolver)
