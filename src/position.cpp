#include "position.h"

namespace ToyRobot
{

Position::Position() :
    m_coordinates(),
    m_direction( )
{}

Position::Position( const Coordinates& coordinates, const Direction& direction ) :
    m_coordinates( coordinates ),
    m_direction( direction )
{}

Position::~Position(){}

const Coordinates Position::GetCoordinates() const
{
    return m_coordinates;
}

const Direction Position::GetDirection() const
{
    return m_direction;
}

void Position::SetCoordinates( const Coordinates& coordinates )
{
    //check whether valid or just set?
    m_coordinates = coordinates;
}

void Position::SetDirection( const Direction& direction )
{
    //check whether valid or just set?
    m_direction = direction;
}

}

