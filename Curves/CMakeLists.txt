# Create library target
add_library(Curves
        src/Circle.cpp
        src/Ellipse.cpp
        src/Helix.cpp
)

# Create library alias
add_library(Curves::Curves ALIAS Curves)

# Public include directory (API exposure)
target_include_directories(Curves
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>
)

# require C++20 for this target
target_compile_features(Curves PUBLIC cxx_std_20)

# Warnings for library
if (MSVC)
    target_compile_options(Curves PRIVATE /W4)
else()
    target_compile_options(Curves PRIVATE -Wall -Wextra -Wpedantic)
endif()