cmake_minimum_required(VERSION 3.10)

project(Question2Assignment)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SOURCE_FILES3 main2a.c functionClass2a.c)
add_executable(MainClass2a ${SOURCE_FILES3})

set(SOURCE_FILES4 main2b.c functionClass2b.c)
add_executable(MainClass2b ${SOURCE_FILES4})

set(SOURCE_FILES1 functionClass2c.c)
add_library(MainClass SHARED ${SOURCE_FILES1})

set(SOURCE_FILES2  main2c.c)
add_executable(MainClass2c ${SOURCE_FILES2})
target_link_libraries(MainClass2c MainClass)