cmake_minimum_required(VERSION 3.20)
project(Date)
set(CMAKE_CXX_STANDARD 17)
add_executable(Date main.cpp Date.h Date.cpp)
if (MSVC)
    target_compile_options(Complex
            PRIVATE /W4          # warnings level
            PRIVATE /WX          # treat all warnings as errors
            )
else()
    target_compile_options(Complex
            PRIVATE -Wall        # basic set of warnings
            PRIVATE -pedantic    # modern C++ inspections
            PRIVATE -Werror      # treat all warnings as errors
            )
endif()