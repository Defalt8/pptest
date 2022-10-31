cmake_minimum_required( VERSION 3.4 )
project( pptest VERSION 0.4.21 )

add_library( pptest INTERFACE include/pptest )
target_include_directories( pptest INTERFACE include )

if( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR} )
	add_executable( pptest_example example.cpp )
	target_link_libraries( pptest_example PRIVATE pptest )
	add_test( NAME pptest_example COMMAND pptest_example )
	enable_testing()
endif()
