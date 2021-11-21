cmake_minimum_required(VERSION 3.16.3)
project("myPC" VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
add_executable(PC zad2.cpp cpu.h cpu.cpp disk.h disk.cpp gpu.h gpu.cpp kbd.h kbd.cpp ram.h ram.cpp)
