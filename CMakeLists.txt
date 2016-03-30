cmake_minimum_required(VERSION 3.3)
project(CPP_lyc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ma.cpp "OJ_Problem/LeetCode_Wiggle Sort II.cpp" Algorithm/MergeSort.cpp Algorithm/DFT.cpp Algorithm/FFT.cpp OJ_Problem/HDU_4609_FFT.cpp OJ_Problem/Hiho_c19_2.cpp.cpp eloop/eloop.cpp eloop/eloop.h epoll.cpp kqueue.cpp kqueue2.cpp CPP_BASE/Cast.cpp CPP_BASE/dp_cast.cpp CPP_BASE/implicit_cast_test1.cpp CPP_BASE/implicit_cast_test2.cpp CPP_BASE/Implicit_cast.cpp)
add_executable(CPP_lyc ${SOURCE_FILES})