cmake_minimum_required(VERSION 3.25)
project(VS2_Clion)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(VS2_Clion
        Pointmass.cpp
        Pointmass.h
        verletSimulator.cpp Link.cpp Link.h)
