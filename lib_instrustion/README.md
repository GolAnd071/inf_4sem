# Libraries installing instructions

*Disclaimer*: this instructions are valid for system Manjaro Linux. But maybe it will help you for other Linux distributions too.<br>
It is recommended to build all libraries from source on Manjaro Linux.<br>
All libraries have full instructions in README.md files in source directories, but these instructions will help you to install libraries faster (without reading installing docs).<br>
Links in this file lead to the versions of libraries that I used. You can find newer versions on official sites/github repositories.

## Gmsh

Download the [source code](https://gmsh.info/#Download), unzip it and then build with this instructions:

`mkdir build`<br>
`cd build`<br>
`cmake -DENABLE_BUILD_DYNAMIC=1 ..`<br>
`sudo make install`

The library will be installed in default system directories, if you want to change it see README.md in the directory with source code.

To use the library you can add a CMakeLists.txt with such code:

`add_library(gmsh SHARED IMPORTED)`<br>
`set_target_properties(gmsh PROPERTIES`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`IMPORTED_LOCATION "/usr/local/lib/libgmsh.so"`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`INTERFACE_INCLUDE_DIRECTORIES "/usr/local/include"`<br>
`)`<br>
`set(GMSH_LIBRARY gmsh)`<br><br>
`target_link_libraries(<executable_name> GMSH_LIBRARY)`

## VTK

[Source code](https://vtk.org/download/#latest). Commands:

`mkdir build`<br>
`cd build`<br>
`cmake ..`<br>
`sudo make install`

Install ParaView. I installed it from pamac (Manjaro Linux package manager). You can try to find it in your package manager or to download from [official website](https://www.paraview.org/download/).

To use the library add to CMakeLists.txt:

`set(CMAKE_CXX_FLAGS "-std=c++11 -g")`<br><br>
`find_package(VTK REQUIRED)`<br>
`include(${VTK_USE_FILE})`<br><br>
`target_link_libraries(<executable_name> ${VTK_LIBRARIES})`

## FEniCSx

[Source code](https://github.com/FEniCS/dolfinx/releases). But there are many dependencies:

`C++ compiler` (no comments)<br>
`Boost` (I installed it from pamac) <br>
`CMake`<br>
`pkg-config` (it was preinstalled on Manjaro Linux)<br>
`Basix` (installed it from pamac)<br>
`pugixml` (installed it from pamac)<br>
`UFCx` (to get the newest version I just downloaded the [source](https://github.com/FEniCS/ffcx/releases) of FFCx and `pip install .` it)<br>
`MPI` (I already had OpenMPI installed)<br>
`HDF5` (just check if your version of HDF5 includes *YOUR* MPI support)<br>
`PETSc` (it is very hard to be built from source, so I recommend to find it in your package manager)<br>
`ParMETIS` (I found it in pamac)

Check all of them before installation. Commands:

`mkdir build`<br>
`cd build`<br>
`cmake ..`<br>
`sudo make install`

To use the newest version of library you will need to read examples. In these examples (or demos) you can find CMakeLists.txt files and working code, that you will need to change.
