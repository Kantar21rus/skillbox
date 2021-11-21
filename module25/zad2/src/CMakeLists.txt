cmake_minimum_required(VERSION 3.16.3)

add_executable(myPC zad2.cpp cpu.cpp disk.cpp gpu.cpp kbd.cpp ram.cpp)
target_include_directories(myPC PUBLIC ${MY_INCLUDE_DIR})
