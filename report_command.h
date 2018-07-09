#ifndef TOYROBOT_REPORT_COMMAND_H
#define TOYROBOT_REPORT_COMMAND_H

#include "command.h"

namespace ToyRobot
{
    class ReportCommand : public Command
    {
        public:
            ReportCommand();
            virtual ~ReportCommand(){};

            virtual void Execute( Position& position, const Grid& grid );
    };
}
#endif

