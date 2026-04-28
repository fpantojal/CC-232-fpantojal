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

# Tests
add_executable(test_bracket_solver_basic tests/test_bracket_solver_basic.cpp)

target_link_libraries(test_bracket_solver_basic PRIVATE BracketSolver)

add_executable(test_bracket_solver_extended tests/test_bracket_solver_extended.cpp)

target_link_libraries(test_bracket_solver_extended PRIVATE BracketSolver)

add_executable(test_bracket_solver_stress tests/test_bracket_solver_stress.cpp)

target_link_libraries(test_bracket_solver_stress PRIVATE BracketSolver)

# Benchmarks
add_executable(bench_bracket_solver benchmark/bench_bracket_solver.cpp)

target_link_libraries(bench_bracket_solver PRIVATE BracketSolver)
