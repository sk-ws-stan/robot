#ifndef TOYROBOT_REPORT_COMMAND_H
#define TOYROBOT_REPORT_COMMAND_H

#include "command.h"

namespace ToyRobot
{
    class Grid;
    class Position;

    class ReportCommand : public Command
    {
    public:
        ReportCommand();
        virtual ~ReportCommand(){};

        virtual const Position Execute( const Position& position, const Grid& grid );
    };
}
#endif

