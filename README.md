# CADEX Assignment project

## Overview

This project implements a small C++20 application that works with several types of 3D parametric curves:

- Circle
- Ellipse
- Helix

The curve implementations are built as a separate static library (`Curves`) and linked to the main executable (`CurvesApp`) using modern CMake targets.

---

## Requirements

To build and run the project, you need:

- **CMake 3.20 or higher**
- **C++20 compatible compiler**
    - MSVC (Visual Studio 2022 recommended)
    - GCC 11+
    - Clang 13+
- **Ninja build system** (recommended)

On Windows with MSVC, use:

```
x64 Native Tools Command Prompt for VS
```

---

## Building with Ninja (Recommended)

### 1. Configure the project

From the project root directory:

```
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
```

Where:
- `-S .` specifies the source directory
- `-B build` specifies the build directory
- `-G Ninja` selects the Ninja generator
- `-DCMAKE_BUILD_TYPE=Release` enables optimized build

---

### 2. Build the project

```
cmake --build build
```

Or:

```
cd build
ninja
```

---

### 3. Run the application

After a successful build:

```
build\CurvesApp.exe
```

Or if you are already inside the `build` directory:

```
CurvesApp.exe
```

---

## Debug Build

To build in Debug mode:

```
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

---

## Alternative: Visual Studio Generator

If you prefer generating a Visual Studio solution:

```
cmake -S . -B build -G "Visual Studio 17 2022"
cmake --build build --config Release
```

This will generate a `.sln` file in the `build` directory.

---

## Output

The compiled executable is located in:

```
build/CurvesApp.exe
```

---

