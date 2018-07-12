#ifndef TOYROBOT_REPORT_COMMAND_H
#define TOYROBOT_REPORT_COMMAND_H

#include "command.h"
#include "grid.h"
#include "position.h"

namespace ToyRobot
{
    class ReportCommand : public Command
    {
    public:
        ReportCommand();
        virtual ~ReportCommand(){};

        virtual const Position Execute( const Position& position, const Grid& grid );
    };
}
#endif

