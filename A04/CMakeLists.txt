cmake_minimum_required(VERSION 3.10.0)
project(a04 VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT MSVC)
	add_compile_options(-Wall)
	add_compile_options(-Werror)
	add_compile_options(-pedantic)
endif(NOT MSVC)

add_executable(a04 main.cpp scopetimer.cpp scopetimer.hpp)
