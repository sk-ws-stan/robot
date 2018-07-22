#include "direction.h"
#include "grid.h"
#include "move_command.h"
#include "position.h"

namespace ToyRobot
{

MoveCommand::MoveCommand() :
    Command()
{}

const Position MoveCommand::Execute( const Position& position, const Grid& grid )
{
    Coordinates newCoordinates = position.GetCoordinates();

    switch( position.GetDirection().GetDirection() )
    {
        case( Direction::NORTH ):
        {
            newCoordinates.SetY( newCoordinates.GetY() + 1 );
            break;
        }
        case( Direction::SOUTH ):
        {
            newCoordinates.SetY( newCoordinates.GetY() - 1 );
            break;
        }
        case( Direction::EAST ):
        {
            newCoordinates.SetX( newCoordinates.GetX() + 1 );
            break;
        }
        case( Direction::WEST ):
        {
            newCoordinates.SetX( newCoordinates.GetX() - 1 );
            break;
        }
        case( Direction::INVALID ):
        default:
        {
            //no move
            break;
        }
    }
    Position returnValue = position;

    if( grid.OnGrid( newCoordinates.GetX(), newCoordinates.GetY() ) )
    {
        returnValue.SetCoordinates( newCoordinates );
    }
    return returnValue;
}

}

