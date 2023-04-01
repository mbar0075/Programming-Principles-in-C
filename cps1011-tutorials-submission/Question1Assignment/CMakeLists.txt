cmake_minimum_required(VERSION 3.10)

project(Question1Assignment)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SOURCE_FILES1 main.c functionClass.c)
add_executable(MainClass ${SOURCE_FILES1})
