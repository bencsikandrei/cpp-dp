## Singleton CMakeLists
include_directories(include)

set(SOURCES "src/FactoryMethod.cpp")

set(RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

## Create the library
add_library(factorymethodp STATIC ${SOURCES})

## Install the library
install(TARGETS factorymethodp DESTINATION "${CMAKE_BINARY_DIR}/lib")

## Compile the tests as well
add_subdirectory(test)
