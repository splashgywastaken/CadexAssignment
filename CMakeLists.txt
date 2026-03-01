cmake_minimum_required(VERSION 3.20)
project(
    CadexAssignment
    VERSION 1.0
    LANGUAGES CXX
)

# Global C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(Curves)

add_executable(CurvesApp
        src/main.cpp
        src/CurveFactories/CurveFactory.h
        src/CurveFactories/CircleFactory.cpp
        src/CurveFactories/CircleFactory.h
        src/CurveFactories/EllipseFactory.cpp
        src/CurveFactories/EllipseFactory.h
        src/CurveFactories/HelixFactory.cpp
        src/CurveFactories/HelixFactory.h
        src/CurveFactories/Curvefactories.h
)

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