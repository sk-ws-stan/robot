#include "direction.h"

namespace ToyRobot
{

Direction::Direction() :
    m_direction( INVALID )
{}

Direction::Direction( const std::string& directionString )
{
    if( directionString == ToString( NORTH ) )
    {
        m_direction = NORTH;
    }
    else if( directionString == ToString( SOUTH ) )
    {
        m_direction = SOUTH;
    }
    else if( directionString == ToString( EAST ) )
    {
        m_direction = EAST;
    }
    else if( directionString == ToString( WEST ) )
    {
        m_direction = WEST;
    }
    else
    {
        m_direction = INVALID;
    }
}

Direction::Direction( const DirectionEnum& direction ) :
    m_direction( direction )
{}

void Direction::TurnLeft()
{
    switch( m_direction )
    {
        case( NORTH ):
        {
            m_direction = WEST;
            break;
        }
        case( SOUTH ):
        {
            m_direction = EAST;
            break;
        }
        case( EAST ):
        {
            m_direction = NORTH;
            break;
        }
        case( WEST ):
        {
            m_direction = SOUTH;
            break;
        }
        case( INVALID ):
        default:
        {
            // log?
        }
    }
}

void Direction::TurnRight()
{
    //contemplated doing arithmetics on the direction enum with the roation, as in direction is ordered cw or ccw [0,3] and rotation {-1,1}:    // newDirection = ( direction + rotation ) % 3
    // decided against it, as it is a) a tight coupling and b) arithmetics with enums is bad style

    switch( m_direction )
    {
        case( NORTH ):
        {
            m_direction = EAST;
            break;
        }
        case( SOUTH ):
        {
            m_direction = WEST;
            break;
        }
        case( EAST ):
        {
            m_direction = SOUTH;
            break;
        }
        case( WEST ):
        {
            m_direction = NORTH;
            break;
        }
        case( INVALID ):
        default:
        {
            // log?
        }
    }
}

const Direction::DirectionEnum Direction::GetDirection() const
{
    return m_direction;
}

void Direction::SetDirection( const DirectionEnum& direction )
{
    //check if valid?
    m_direction = direction;
}

const std::string Direction::ToString() const
{
    return ToString( m_direction );
}

const std::string Direction::ToString( const DirectionEnum& direction )
{
    //contemplated doing arithmetics on the direction enum with the roation, as in direction is ordered cw or ccw [0,3] and rotation {-1,1}:    // newDirection = ( direction + rotation ) % 3
    // decided against it, as it is a) a tight coupling and b) arithmetics with enums is bad style

    std::string returnValue;

    switch( direction )
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
        case( INVALID ):
        default:
        {
            returnValue = "INVALID";
            break;
        }
    }
    return returnValue;
}

}

