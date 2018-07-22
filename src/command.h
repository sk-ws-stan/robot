#ifndef TOYROBOT_COMMAND_H
#define TOYROBOT_COMMAND_H

namespace ToyRobot
{
    class Grid;
    class Position;

    class Command
    {
    public:
        Command(){};
        virtual ~Command(){};

        virtual const Position Execute( const Position& position, const Grid& grid ) = 0;
    };
}
#endif

