#include "robot.h"
#include "command.h"

namespace ToyRobot
{

Robot::Robot( const Grid& grid ) :
    m_grid( grid ),
    m_position()
{}

void Robot::DoExecute( Command& command )
{
   m_position = command.Execute( m_position, m_grid );
}

}

