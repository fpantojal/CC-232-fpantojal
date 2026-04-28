cmake_minimum_required(VERSION 3.10)
project(PC2_BracketSolver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Crear la librería
add_library(BracketSolver STATIC
    src/BracketSolver.cpp
)

# Añadir include directories para la librería
target_include_directories(BracketSolver PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Crear el ejecutable
add_executable(main src/main.cpp)

# Vincular la librería al ejecutable
target_link_libraries(main PRIVATE BracketSolver)

# Incluir headers para el ejecutable
target_include_directories(main PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
