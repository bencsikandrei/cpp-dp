## Singleton CMakeLists
include_directories(include)

set(FM_SOURCES "src/FactoryMethod.cpp")
set(F_SOURCES "src/Factory.cpp")

set(RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

## Create the library
add_library(factorymethodp STATIC ${FM_SOURCES})
add_library(factorydp STATIC ${F_SOURCES})

## Install the library
install(TARGETS factorymethodp DESTINATION "${CMAKE_BINARY_DIR}/lib")
install(TARGETS factorydp DESTINATION "${CMAKE_BINARY_DIR}/lib")

## Compile the tests as well
add_subdirectory(test)
