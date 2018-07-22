#ifndef TOYROBOT_ROTATE_COMMAND_H
#define TOYROBOT_ROTATE_COMMAND_H

#include "command.h"
#include "rotation.h"

namespace ToyRobot
{
    class Grid;
    class Position;

    class RotateCommand : public Command
    {
    public:
        RotateCommand( const Rotation& rotation );
        virtual ~RotateCommand(){};

        virtual const Position Execute( const Position& position, const Grid& grid );

    private:
        Rotation m_rotation;
    };
}
#endif
