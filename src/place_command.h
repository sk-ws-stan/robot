#ifndef TOYROBOT_PLACE_COMMAND_H
#define TOYROBOT_PLACE_COMMAND_H

#include "command.h"
#include "grid.h"
#include "position.h"

namespace ToyRobot
{
    class PlaceCommand : public Command
    {
    public:
        PlaceCommand( const Position& position );
        virtual ~PlaceCommand(){};

        virtual const Position Execute( const Position& position, const Grid& grid );
    private:
        Position m_position;
    };
}
#endif

