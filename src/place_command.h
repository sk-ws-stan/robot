#ifndef TOYROBOT_PLACE_COMMAND_H
#define TOYROBOT_PLACE_COMMAND_H

#include "command.h"

namespace ToyRobot
{
    class PlaceCommand : public Command
    {
    public:
        PlaceCommand();
        virtual ~PlaceCommand(){};

        virtual const Position Execute( const Position& position, const Grid& grid );
    };
}
#endif

