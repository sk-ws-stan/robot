#include "place_command.h"

namespace ToyRobot
{

PlaceCommand::PlaceCommand() :
    Command()
{}

const Position PlaceCommand::Execute( const Position& position, const Grid& grid )
{
    Position returnValue;

    if( grid.OnGrid( position.GetCoordinates().GetX(), position.GetCoordinates().GetY() ) )
    {
        returnValue = position;
    }
    return returnValue;
}

}
