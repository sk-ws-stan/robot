#find_package( Boost COMPONENTS test )

set( TARGET test_toy_robot )

# indicates the location of the boost installation tree.
# hard-coded for our simple example.
#set(BOOST_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/boost_test/include/boost/test/included)

# creates the executable
#add_executable(test_executable test_file.cpp)

# indicates the include paths
#target_include_directories( ${TARGET} ${BOOST_INCLUDE_DIRS})
#include_directories( ${BOOST_INCLUDE_DIRS})

# declares a test with our executable
#add_test(NAME test1 COMMAND test_executable)
#link against boost test

#INCLUDE_DIRECTORIES( ${SOURCE_CODE_BASE_DIR} )
#message( STATUS "Boost_LIBRARY_DIRS=${Boost_LIBRARY_DIRS}")
#LINK_DIRECTORIES( "../src" )

add_executable( ${TARGET}
 #   ${BOOST_INCLUDE_DIRS}/unit_test.hpp
    main.cpp
    test_coordinates.cpp
    test_direction.cpp
    test_grid.cpp
    test_move_command.cpp
    test_parser.cpp
    test_place_command.cpp
    test_position.cpp
    test_report_command.cpp
    test_rotate_command.cpp
#    test_rotation.cpp
)

target_link_libraries( ${TARGET}
    LIB_ROBOT
    ${Boost_TEST_EXEC_MONITOR_LIBRARY}
    ${BOOST_UNIT_TEST_FRAMEWORK_LIBRARY}
)
