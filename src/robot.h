#ifndef TOYROBOT_ROBOT_H
#define TOYROBOT_ROBOT_H

#include "grid.h"
#include "position.h"

#include <memory>

namespace ToyRobot
{
    class Command;

    class Robot
    {
    public:
        Robot( const Grid& grid );
        ~Robot(){};

        void DoExecute( std::shared_ptr< Command >& command );

    private:
        Grid m_grid;
        Position m_position;
    };
}
#endif

