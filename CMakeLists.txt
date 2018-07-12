cmake_minimum_required( VERSION 2.8.4 )

option( BUILD_UNIT_TEST "unit tests?" OFF )

add_subdirectory( src )

if( ${BUILD_UNIT_TESTS} )
    add_subdirectory( test )
endif()

