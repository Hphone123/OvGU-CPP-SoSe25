cmake_minimum_required(VERSION 3.10.0)
project(a05 VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT MSVC)
	add_compile_options(-Wall)
	add_compile_options(-Werror)
	add_compile_options(-pedantic)
	add_compile_options(-g)
endif(NOT MSVC)

add_executable(a05 example.cpp immstring.cpp immstring.hpp)
