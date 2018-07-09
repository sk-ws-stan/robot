#include "coordinates.h"

namespace ToyRobot
{

Coordinates::Coordinates() :
    m_x( -1 ),
    m_y( -1 )
{}

Coordinates::Coordinates( int x, int y ) :
    m_x( x ),
    m_y( y )
{}

void Coordinates::SetCoordinates( int x, int y )
{
    m_x = x;
    m_y = y;
}

void Coordinates::SetX( int x )
{
    m_x = x;
}

void Coordinates::SetY( int y )
{
    m_y = y;
}

const int Coordinates::GetX() const
{
    return m_x;
}

const int Coordinates::GetY() const
{
    return m_y;
}

}

