set( TARGET test_toy_robot )

add_executable( ${TARGET}
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
    test_rotation.cpp
)

target_link_libraries( ${TARGET}
    LIB_ROBOT
    #if not set this does not do any harm
    ${Boost_TEST_EXEC_MONITOR_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
#building unit tests is currently disabled via conan - leaving this logic here regardless
#to cater for conan's inability of providing individual libs in boost
foreach( boost_LIB ${boost_LIBS} )
    string( FIND ${boost_LIB} "unit_test" UT_FOUND )
    string( FIND ${boost_LIB} "exec_moni" EX_FOUND )
    if( UT_FOUND GREATER "-1" OR EX_FOUND GREATER "-1" )
        target_link_libraries( ${TARGET} ${boost_LIB} )
    endif()
endforeach()
