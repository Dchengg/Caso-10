cmake_minimum_required(VERSION 3.14)
project(Parallel_Matroids C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

add_executable(Parallel_Matroids main.c)
add_executable(test test.c)

# added -fopenmp
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

set(SOURCE_FILES main.c)
add_executable(openmp_test_clion ${SOURCE_FILES})