## Singleton CMakeLists
include_directories(include)

set(OLD_SOURCES "src/Singleton_old.cpp")
set(NEW_SOURCES "src/Singleton.cpp")

set(RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

## Create the library
add_library(singletondp STATIC ${OLD_SOURCES})
add_library(singletonnewdp STATIC ${NEW_SOURCES})

## Install the library
install(TARGETS singletondp DESTINATION "${CMAKE_BINARY_DIR}/lib")
install(TARGETS singletonnewdp DESTINATION "${CMAKE_BINARY_DIR}/lib")

## Compile the tests as well
add_subdirectory(test)
