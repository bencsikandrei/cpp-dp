## Patterns CMakeLists

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
		message("-- Linked with library: ${libs}")
		target_link_libraries(${tcname} ${libs})
	endif()
	message("-- Added gtest: ${tcname}")
endmacro()

add_subdirectory(singleton)
add_subdirectory(strategy)
add_subdirectory(builder)
add_subdirectory(factory)
