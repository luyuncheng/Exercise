cmake_minimum_required(VERSION 3.3)
project(CPP_lyc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ma.cpp "LeetCode_Wiggle Sort II.cpp" MergeSort.cpp DFT.cpp FFT.cpp HDU_4609_FFT.cpp Hiho_c19_2.cpp.cpp)
add_executable(CPP_lyc ${SOURCE_FILES})