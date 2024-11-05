cmake_minimum_required(VERSION 3.28)
project(avl)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(avl
        avl.h
        avl_impl.h
        hw1-test.cc
        hw1.h)
