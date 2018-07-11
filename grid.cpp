#include "grid.h"

namespace ToyRobot
{
Grid::Grid( int x, int y ) :
    m_x( x ),
    m_y( y )
{
    //check x,y > 0
}

const int Grid::GetX() const
{
    return m_x;
}

const int Grid::GetY() const
{
    return m_y;
}

const bool Grid::OnGrid( const int& x, const int& y ) const
{
    return ( ( 0 <= x <= m_x ) && ( 0 <= y <= m_y ) );
}

}

