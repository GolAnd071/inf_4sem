cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_FLAGS "-std=c++11 -g")

project(01_lab)
add_executable(step0task1 step0/task1.cpp)
add_executable(step0task2 step0/task2.cpp)
add_executable(step0task3 step0/task3.cpp)

add_executable(step1 step1/task.cpp)

add_executable(step2 step2/task.cpp)

# gmsh укажем явно (потому что он был просто распакован руками)
add_library(gmsh SHARED IMPORTED)
set_target_properties(gmsh PROPERTIES
    IMPORTED_LOCATION "/usr/local/lib/libgmsh.so"
    INTERFACE_INCLUDE_DIRECTORIES "/usr/local/include"
)
set(GMSH_LIBRARY gmsh)

# Укажем библиотеки для линковки
target_link_libraries(step0task1 ${GMSH_LIBRARY})
target_link_libraries(step0task2 ${GMSH_LIBRARY})
target_link_libraries(step0task3 ${GMSH_LIBRARY})

target_link_libraries(step1 ${GMSH_LIBRARY})

target_link_libraries(step2 ${GMSH_LIBRARY})
