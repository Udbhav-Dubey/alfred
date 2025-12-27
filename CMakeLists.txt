cmake_minimum_required(VERSION 3.20)

project(alfred
    VERSION 1.0
    LANGUAGES CXX
)

# Tell CMake: we want C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Good default warnings
add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(alfred
    src/main.cpp
    src/intro.cpp
    src/journal.cpp
    src/habits.cpp
    src/menu.cpp
    src/quotes.cpp
    src/heatmap.cpp
)

