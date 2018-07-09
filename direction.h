#ifndef TOYROBOT_DIRECTION_H
#define TOYROBOT_DIRECTION_H

#include <string>

namespace ToyRobot
{
    enum DirectionEnum
    {
        NORTH = 0,
        SOUTH = 1,
        EAST = 2,
        WEST = 3,
        INVALID = 4,
    };

    class Direction
    {
    public:
        Direction();
        ~Direction(){};

        const DirectionEnum GetDirection() const;
        const std::string GetDirectionAsString() const;

    private:
        DirectionEnum m_direction;
    };
}
#endif

