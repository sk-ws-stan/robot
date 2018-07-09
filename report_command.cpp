#include "report_command.h"

#include <iostream>

namespace ToyRobot
{

ReportCommand::ReportCommand() :
    Command()
{}

void ReportCommand::Execute( Position& position, const Grid& grid )
{
    //what if position not set -> cout error

    std::cout << position.GetCoordinates().GetX() << "," << position.GetCoordinates().GetY() << "," << position.GetDirection().GetDirectionAsString() << std::endl;
}

}

