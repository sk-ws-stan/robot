#include "grid.h"
#include "robot.h"

#include <iostream>

using namespace ToyRobot;

const int c_GridDefaultSizeX = 4;  // start counting from 0
const int c_GridDefaultSizeY = 4;

int main (int argc, char *argv[])
{
    try
    {
        //boost program options for grid size?

        //need parser

        //grid
        Grid grid = Grid( c_GridDefaultSizeX, c_GridDefaultSizeY );

        //robot
        Robot robot = Robot( grid );


        if( 2 <= argc )
        {
            //load robot commands from file
        }
        else
        {
            //get commands from command line
        }

    }
    catch( ... )
    {
        std::cerr << "Caught unknown exception" << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}
