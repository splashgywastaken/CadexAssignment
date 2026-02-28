cmake_minimum_required(VERSION 3.30)
project(
    CadexAssignment
    VERSION 0.1
    LANGUAGES CXX
)

# Global C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(Curves)

add_executable(CurvesApp main.cpp)

target_link_libraries(
        CurvesApp
        PRIVATE
            Curves::Curves
)

# Warnings
if(MSVC)
    target_compile_options(CurvesApp PRIVATE /W4)
else()
    target_compile_options(CurvesApp PRIVATE -Wall -Wextra -Wpedantic)
endif()