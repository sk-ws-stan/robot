#include "rotate_command.h"

namespace ToyRobot
{

RotateCommand::RotateCommand( const Rotation& rotation ) :
    Command(),
    m_rotation( rotation )
{}

const Position RotateCommand::Execute( const Position& position, const Grid& grid )
{
    Position returnValue = position;
    Direction newDirection( position.GetDirection() );

    switch( m_rotation.m_rotation )
    {
        case( Rotation::LEFT ):
        {
            newDirection.TurnLeft();
            break;
        }
        case( Rotation::RIGHT ):
        {
            newDirection.TurnRight();
            break;
        }
        case( Rotation::INVALID ):
        default:
        {
            //log?
            break;
        }
    }
    returnValue.SetDirection( newDirection );

    return returnValue;
}

}
