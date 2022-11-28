cmake_minimum_required( VERSION 3.4 )
project( pptest VERSION 1.7.32 LANGUAGES CXX )

option( BUILD_TESTS ON )

add_library( pptest INTERFACE )
target_include_directories( pptest INTERFACE include )
set_target_properties( pptest PROPERTIES PUBLIC_HEADER "include/pptest;include/colored_printer" )

if( BUILD_TESTS
	AND ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR} )
	install( TARGETS pptest PUBLIC_HEADER DESTINATION include COMPONENT Development )

	add_executable( pptest_example example.cpp )
	target_link_libraries( pptest_example PRIVATE pptest )

	add_executable( pptest_test test.cpp )
	target_link_libraries( pptest_test PRIVATE pptest )
	add_test( NAME pptest_test COMMAND pptest_test )
	enable_testing()
endif()
