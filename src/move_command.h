#ifndef TOYROBOT_MOVE_COMMAND_H
#define TOYROBOT_MOVE_COMMAND_H

#include "command.h"

namespace ToyRobot
{
    class Grid;
    class Position;

    class MoveCommand : public Command
    {
    public:
        MoveCommand();
        virtual ~MoveCommand(){};

        virtual const Position Execute( const Position& position, const Grid& grid );
    };
}
#endif

