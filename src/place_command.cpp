#include "place_command.h"

namespace ToyRobot
{

PlaceCommand::PlaceCommand( const Position& position ) :
    Command(),
    m_position( position )
{}

const Position PlaceCommand::Execute( const Position& /*position*/, const Grid& grid )
{
    Position returnValue;

    if( ( grid.OnGrid( m_position.GetCoordinates().GetX(), m_position.GetCoordinates().GetY() ) ) &&
        ( m_position.GetDirection().GetDirection() != Direction::INVALID ) )
    {
        returnValue = m_position;
    }
    return returnValue;
}

}

