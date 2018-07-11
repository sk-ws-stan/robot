#include "report_command.h"

#include <iostream>

namespace ToyRobot
{

ReportCommand::ReportCommand() :
    Command()
{}

const Position ReportCommand::Execute( const Position& position, const Grid& grid )
{
    //what if position not set -> cout error
    Position returnValue = position;

    std::cout << position.GetCoordinates().GetX() << "," << position.GetCoordinates().GetY() << "," << position.GetDirection().ToString() << std::endl;

    return returnValue;
}

}

