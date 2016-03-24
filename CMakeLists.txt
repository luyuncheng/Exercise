cmake_minimum_required(VERSION 3.3)
project(CPP_lyc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ma.cpp "OJ_Problem/LeetCode_Wiggle Sort II.cpp" Algorithm/MergeSort.cpp Algorithm/DFT.cpp Algorithm/FFT.cpp OJ_Problem/HDU_4609_FFT.cpp OJ_Problem/Hiho_c19_2.cpp.cpp eloop/eloop.cpp eloop/eloop.h)
add_executable(CPP_lyc ${SOURCE_FILES})