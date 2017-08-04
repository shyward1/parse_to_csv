cmake_minimum_required(VERSION 3.8)
project(parse_to_csv)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(parse_to_csv ${SOURCE_FILES})