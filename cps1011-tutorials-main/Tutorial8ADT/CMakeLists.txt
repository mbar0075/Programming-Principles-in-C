cmake_minimum_required(VERSION 3.20)

project(Labs8 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SOURCE_FILES1 Question1.c sgets.c)
add_executable(Question1 ${SOURCE_FILES1})

set(SOURCE_FILES2 Question2.c sgets.c)
add_executable(Question2 ${SOURCE_FILES2})

set(SOURCE_FILES3 Question3.c sgets.c)
add_executable(Question3 ${SOURCE_FILES3})

set(SOURCE_FILES4 Question4.c sgets.c)
add_executable(Question4 ${SOURCE_FILES4})

set(SOURCE_FILES5 Question5.c)
add_executable(Question5 ${SOURCE_FILES5})

set(SOURCE_FILES6 Question6list.c Question6films.c sgets.c)
add_executable(Question6 ${SOURCE_FILES6})

set(SOURCE_FILES7 Question6list.c )
add_library(list SHARED ${SOURCE_FILES7})

set(SOURCE_FILES11 Question6films.c sgets.c)
add_executable(Question7 ${SOURCE_FILES11})
target_link_libraries(Question7 list)

set(SOURCE_FILES8 Question8.c)
add_executable(Question8 ${SOURCE_FILES8})

set(SOURCE_FILES9 Question9list.c )
add_library(list7 STATIC ${SOURCE_FILES9})

set(SOURCE_FILES12 Question9films.c sgets.c)
add_executable(Question9 ${SOURCE_FILES12})
target_link_libraries(Question9 list7)

set(SOURCE_FILES10 sgets.c)
add_library(SGETS SHARED ${SOURCE_FILES10})

set(SOURCE_FILESZ Question10.c)
add_executable(Question10 ${SOURCE_FILESZ})
target_link_libraries(Question10 SGETS)
