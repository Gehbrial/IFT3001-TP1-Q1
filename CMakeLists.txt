cmake_minimum_required(VERSION 3.12)
project(IFT3001_TP1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(IFT3001_TP1
        division.cpp
        division.hpp
        main.cpp
        polynome.cpp
        polynome.hpp
        rationnel.cpp
        rationnel.hpp)
