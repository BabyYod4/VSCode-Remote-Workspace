cmake_minimum_required( VERSION 2.8 )

## Sources and headers
include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )
include_directories( ${INCLUDE_DIR} )
#include_directories( "<<path/to/include/" )

## Find all source and header files to be compiled from include folder
file( GLOB_RECURSE INCLUDES "${INCLUDE_DIR}/*.cc" "${INCLUDE_DIR}/*.cpp" "${INCLUDE_DIR}/*.hpp" "${INCLUDE_DIR}/*.c" "${INCLUDE_DIR}/*.h" )

## Find all source and header files to be compiled into object files
file( GLOB_RECURSE SOURCES *.cc *.hh *.cpp *.hpp *.c *.h )

## Add Libraries
# add_library(<<LibraryName>> SHARED IMPORTED)
# set_property(TARGET <<LibraryName>>  PROPERTY IMPORTED_LOCATION "/path/to/lib/")

## Find Required Packages
# find_package(<<LibraryName>> REQUIRED)



## C++ compiler options

### Enable Warnings 
# set( CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11 -pthread -L/usr/local/libs" )

### Disable Warnings 
set( CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11 -L/usr/local/libs" ) 

### Compiler settings
set( CMAKE_CXX_FLAGS_DEBUG "-g -O0" )
set( CMAKE_CXX_FLAGS_RELEASE "-O3" )
set( CMAKE_CXX_STANDARD_REQUIRED ON ) #...is required...
set( CMAKE_CXX_EXTENSIONS ON ) #...with compiler extensions like gnu++11


## Source file containing the "main" function
set( MAIN_SOURCES main.c )
## Specify a name for the generated executable file
set( MAIN_EXE_NAME ${PROJECT_NAME_}.exe )


## 1. Compile...
add_executable( ${MAIN_EXE_NAME} ${MAIN_SOURCES} ${SOURCES} ${INCLUDES} )


## 2. Link...
target_link_libraries( ${MAIN_EXE_NAME} )
# target_link_libraries(${MAIN_EXE_NAME} <<Libraryname>> )



## 3. Install...
install( TARGETS ${MAIN_EXE_NAME}
         RUNTIME DESTINATION bin )
