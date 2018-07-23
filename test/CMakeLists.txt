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

#boost 1.50 uses test exec monitor, 1.61 prg exec monitor
set( EXEC_MONITOR "" )
if( DEFINED Boost_TEST_EXEC_MONITOR_LIBRARY )
    set( EXEC_MONITOR ${Boost_TEST_EXEC_MONITOR_LIBRARY} )
else()
    set( EXEC_MONITOR ${Boost_PRG_EXEC_MONITOR_LIBRARY} )
endif()
target_link_libraries( ${TARGET}
    LIB_ROBOT
    ${EXEC_MONITOR}
    ${BOOST_UNIT_TEST_FRAMEWORK_LIBRARY}
)
