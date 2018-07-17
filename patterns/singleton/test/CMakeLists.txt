## Singleton Tests CMakeLists
message("-- Current runtime output: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests/)

message("-- Setting new runtime output: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

## Add a google test
macro(add_gtest tcname source)
	## Add the test executable
	add_executable(${tcname} ${source})
	## If extra argument given
	set(optional_args ${ARGN})
	list(LENGTH optional_args nb_optional_args)
	## Link library if given
	if(${nb_optional_args} GREATER 0)
		list(GET optional_args 0 libs)
		message(${libs})
		target_link_libraries(${tcname} ${libs})
	endif()
endmacro()

## Add more tests
add_gtest(TestSingleton TestSingleton.cpp singletondp)
add_gtest(TestSingletonNew TestSingletonNew.cpp)
