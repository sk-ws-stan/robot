#ifndef TOYROBOT_MOVE_COMMAND_H
#define TOYROBOT_MOVE_COMMAND_H

#include "command.h"
#include "grid.h"
#include "position.h"

namespace ToyRobot
{
    class MoveCommand : public Command
    {
    public:
        MoveCommand();
        virtual ~MoveCommand(){};

        virtual const Position Execute( const Position& position, const Grid& grid );
    };
}
#endif

