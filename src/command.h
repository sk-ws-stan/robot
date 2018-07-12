#ifndef TOYROBOT_COMMAND_H
#define TOYROBOT_COMMAND_H

#include "grid.h"
#include "position.h"

namespace ToyRobot
{
    class Command
    {
    public:
        Command(){};
        virtual ~Command(){};

        virtual const Position Execute( const Position& position, const Grid& grid ) = 0;
    };
}
#endif

