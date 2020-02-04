# cmake-workspace

## Introduction:
This is a simple cmake-template workspace to use in a CLI envoiment. The folder structure is as followed
```bash
├── bin --> contains executables
├── build --> contains build files makde by cmake 
├── CMakeLists.txt --> contain global variables, etc
├── include --> contains external source code from include submodule
│   ├── foo.cpp
│   ├── foo.hpp
│   └── test
│       ├── test.cpp
│       └── test.hpp

├── lib --> contain generated and used library files
├── README.md
├── run --> used to compile and execute code
└── src --> conains all base source code
    ├── CMakeLists.txt --> used to configure libary to work with source code 
    └── main.cpp
```

## Before Usage:

To use the workspace, you should take do the following. 

In the workspace folder: 
- Open the file 'run' and change {A NAME HERE} in the line "EXEC_NAME={A NAME HERE}"
to a custom executable name. In this guide we will refer to this name as 'UNAME'.

- Open the file 'CMakeLists.txt' and change "CmakeTest" in the line "set ( PROJECT_NAME_ "CmakeTest" )" to the UNAME.


## Usage:
To test the program or use the build envoirments execute the following commands into the cloned folder

```bash
### Only need to be performed once if no build folder present!
mkdir build
cd build 
cmake ..

cd ..

### Needs to be performed anytime you updated the code. 

## Compiling and Running the executable 
./run 

## if you get a premission error 
sudo chmod +x run
./run

```

You can use source and header files from the include folder in the following ways:
```c++
#include <foo.hpp>
#include <test/test.hpp>
```


## Adding other sub-models (that use the include folder)
1. Create a new folder in the cmake-workspace
2. Edit the CMakeList.txt in the cmake-workspace and add the following code after line: " set ( INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include" ) " 
   - set ( <<NAME_OF_DIR>> "${CMAKE_CURRENT_SOURCE_DIR}/<<NAME_OF_FOLDER>>" )
3. Edit the CMakeList.txt in the cmake-workspace/src and do the following:
   - add the following code after the line: " include_directories( ${INCLUDE_DIR} ) "
       - include_directories( ${<<NAME_OF_DIR>>} )
   - add the following code aftr the line: " file( GLOB_RECURSE INCLUDES "${INCLUDE_DIR}/*.cc" "${INCLUDE_DIR}/*.cpp" "${INCLUDE_DIR}/*.hpp" "${INCLUDE_DIR}/*.c" "${INCLUDE_DIR}/*.h" ) "
       - file( GLOB_RECURSE <<SOME_NAME>> "${<<NAME_OF_DIR>>}/*.cc" "${<<NAME_OF_DIR>>}/*.cpp" "${<<NAME_OF_DIR>>}/*.hpp" "${<<NAME_OF_DIR>>}/*.c" "${<<NAME_OF_DIR>>}/*.h" ) 
   - append the content of line: " add_executable( ${MAIN_EXE_NAME} ${MAIN_SOURCES} ${SOURCES} ${INCLUDES} ) "
       - So it becomes: " add_executable( ${MAIN_EXE_NAME} ${MAIN_SOURCES} ${SOURCES} ${INCLUDES} ${<<SOME_NAME>>} ) "
4. Add the source code with folders etc to the new folder you made in step 1
5. 

All submodules can use each others and the include folders source files in the same wa the src source files can use it. 
So for example:

```bash
├── bin
├── build
├── CMakeLists.txt
├── external_module --> the new module you created in step 1
│   ├── hoi.cpp
│   └── hoi.hpp
├── include
│   ├── lol
│   │   ├── test2.cpp
│   │   ├── test2.hpp
│   │   ├── test.cpp
│   │   └── test.hpp
│   ├── test.cpp
│   └── test.hpp
└── src
    ├── CMakeLists.txt
    ├── main.cpp

```

```c++
// hoi.hpp
#ifndef HOI_HPP
#define HOI_HPP

#include <test.hpp>
#include <lol/test.hpp>

class foo4{
private:
    foo bar;
public: 
    foo4();
    int test();

};

#endif //HOI_HPP

// main.cpp
#include <test.hpp>
#include <lol/test2.hpp>
#include <lol/test.hpp>
#include <hoi.hpp>

int main(){
    foo bar;
    foo2 bar2;
    foo3 bar3;
    foo4 bar4;

    std::cout << bar.test();
    std::cout << bar2.test();
    std::cout << bar3.test();
    std::cout << bar4.test();
    
    return 0;
}
``` 
