set( TARGET test_toy_robot_header_only )

add_executable( ${TARGET}
    main.cpp
)

target_link_libraries( ${TARGET}
    LIB_ROBOT
)
