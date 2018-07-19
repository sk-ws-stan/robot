set( TARGET LIB_ROBOT )

add_library( ${TARGET}
    command.h
    coordinates.cpp
    coordinates.h
    direction.cpp
    direction.h
    grid.cpp
    grid.h
    move_command.cpp
    move_command.h
    parser.cpp
    parser.h
    place_command.cpp
    place_command.h
    position.cpp
    position.h
    report_command.cpp
    report_command.h
    robot.cpp
    robot.h
    rotation.h
    rotate_command.cpp
    rotate_command.h
)
