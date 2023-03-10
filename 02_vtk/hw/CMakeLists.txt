cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_FLAGS "-std=c++11 -g")

project(vtkdemo)
add_executable(task task.cpp)

# Найдём VTK
find_package(VTK REQUIRED)
# ... и подключим её со всеми её компонентами её нативными средствами
include(${VTK_USE_FILE})

# gmsh укажем явно по кусочкам (потому что он был просто распакован руками)
add_library(gmsh SHARED IMPORTED)
set_target_properties(gmsh PROPERTIES
    IMPORTED_LOCATION "/usr/local/lib/libgmsh.so"
    INTERFACE_INCLUDE_DIRECTORIES "/usr/local/include"
)
set(GMSH_LIBRARY gmsh)

# если бы gmsh был поставлен прилично, то можно было бы примерно вот так
#find_package(gmsh REQUIRED)
#include_directories(${GMSH_INCLUDE_DIR})
#target_link_libraries(tetr3d ${GMSH_LIBRARY})

# Укажем библиотеки для линковки
target_link_libraries(task ${VTK_LIBRARIES})
target_link_libraries(task ${GMSH_LIBRARY})
