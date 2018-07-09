#include "robot.h"
#include "command.h"

namespace ToyRobot
{

Robot::Robot( const Grid& grid ) :
    m_grid( grid ),
    m_position()
{}

void Robot::ExecuteCommand( Command& command )
{
   command.Execute( m_position, m_grid );
}

}

