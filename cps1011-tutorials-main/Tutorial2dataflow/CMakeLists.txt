cmake_minimum_required(VERSION 3.20)

project(Labs2 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SOURCE_FILES1 Question1.c)
add_executable(app1 ${SOURCE_FILES1})

set(SOURCE_FILES2 Question2.c)
add_executable(app2 ${SOURCE_FILES2})

set(SOURCE_FILES3 Question3.c)
add_executable(app3 ${SOURCE_FILES3})

set(SOURCE_FILES4 Question4.c)
add_executable(Question4 ${SOURCE_FILES4})

set(SOURCE_FILES5 Question5.c)
add_executable(Question5 ${SOURCE_FILES5})

set(SOURCE_FILES6 Question6.c)
add_executable(app6 ${SOURCE_FILES6})

set(SOURCE_FILES7 Question7.c)
add_executable(app7 ${SOURCE_FILES7})

set(SOURCE_FILES8 Question8.c)
add_executable(app8 ${SOURCE_FILES8})