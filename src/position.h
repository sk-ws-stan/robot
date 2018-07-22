#ifndef TOYROBOT_POSITION_H
#define TOYROBOT_POSITION_H

#include "coordinates.h"
#include "direction.h"

namespace ToyRobot
{
    class Position
    {
    public:
        Position();
        Position( const Coordinates& coordinates, const Direction& direction );
        ~Position(){};

        const Coordinates GetCoordinates() const;
        const Direction GetDirection() const;

        void SetCoordinates( const Coordinates& coordinates );
        void SetDirection( const Direction& direction );

    private:
        Coordinates m_coordinates;
        Direction m_direction;
    };
}
#endif
