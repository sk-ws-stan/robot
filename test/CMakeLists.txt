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
    ${Boost_TEST_EXEC_MONITOR_LIBRARY}
    ${BOOST_UNIT_TEST_FRAMEWORK_LIBRARY}
)
