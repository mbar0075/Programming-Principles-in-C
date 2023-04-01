cmake_minimum_required(VERSION 3.20)

project(Lab1 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SOURCE_FILES1 main.c)
add_executable(app1 ${SOURCE_FILES1})

set(SOURCE_FILES2 Question2.c)
add_executable(app2 ${SOURCE_FILES2})

set(SOURCE_FILES3 Question1.c)
add_executable(app3 ${SOURCE_FILES3})

set(SOURCE_FILES4 Question3.c)
add_executable(app4 ${SOURCE_FILES4})

set(SOURCE_FILES5 Question4.c)
add_executable(app5 ${SOURCE_FILES5})

set(SOURCE_FILES6 Question8.c)
add_executable(app6 ${SOURCE_FILES6})