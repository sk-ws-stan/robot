#ifndef TOYROBOT_DIRECTION_H
#define TOYROBOT_DIRECTION_H

#include <string>

namespace ToyRobot
{
    class Direction
    {
    public:

        enum DirectionEnum
        {
            NORTH = 0,
            SOUTH = 1,
            EAST = 2,
            WEST = 3,
            INVALID = 4,
        };

        Direction();
        Direction( const DirectionEnum& direction );
        ~Direction(){};

        void TurnLeft();
        void TurnRight();
        const DirectionEnum GetDirection() const;
        const std::string ToString() const;
        static const std::string ToString( const DirectionEnum& directionn );

    private:
        DirectionEnum m_direction;
    };
}
#endif

