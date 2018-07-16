## Singleton Tests CMakeLists
message("-- Current runtime output: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests/)

message("-- Setting new runtime output: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

## Add a google test
macro(add_gtest tcname source libs)
	message(${libs})
	## Add the test executable
	add_executable(${tcname} ${source})
	## Link library
	target_link_libraries(${tcname} ${libs})
endmacro()

## Add more tests
add_gtest(TestSingleton TestSingleton.cpp singletondp)
add_gtest(TestSingletonNew TestSingletonNew.cpp singletonnewdp)
