cmake_minimum_required(VERSION 3.10)
project(SignalLab)

set(CMAKE_CXX_STANDARD 17)

add_executable(signalLab
    src/main.cpp
    src/generator.cpp
    src/quantizer.cpp
    src/fft.cpp
    src/spectrum.cpp
)


