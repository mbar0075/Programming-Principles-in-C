cmake_minimum_required(VERSION 3.20)

project(Labs4 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SOURCE_FILES1 Question1.c Question2.c Question3.c Question4.c Question5.c Question6.c Question7.c Question8.c)
add_executable(main ${SOURCE_FILES1})





