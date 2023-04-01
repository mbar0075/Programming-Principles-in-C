cmake_minimum_required(VERSION 3.20)

project(Labs7 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SOURCE_FILES1 Question1.c)
add_executable(Question1 ${SOURCE_FILES1})

set(SOURCE_FILES2 Question2.c sgets.c)
add_executable(Question2 ${SOURCE_FILES2})

set(SOURCE_FILES3 Question3.c sgets.c)
add_executable(Question3 ${SOURCE_FILES3})

set(SOURCE_FILES4 Question4.c sgets.c)
add_executable(Question4 ${SOURCE_FILES4})

