#include "direction.h"

namespace ToyRobot
{

Direction::Direction() :
    m_direction( INVALID )
{}

const DirectionEnum Direction::GetDirection() const
{
    return m_direction;
}

const std::string Direction::GetDirectionAsString() const
{
    std::string returnValue = "INVALID";

    switch( m_direction )
    {
        case( NORTH ):
        {
            returnValue = "NORTH";
            break;
        }
        case( SOUTH ):
        {
            returnValue = "SOUTH";
            break;
        }
        case( EAST ):
        {
            returnValue = "EAST";
            break;
        }
        case( WEST ):
        {
            returnValue = "WEST";
            break;
        }
        default:
        {
            returnValue = "INVALID";
            break;
        }
    }
    return returnValue;
}

}

