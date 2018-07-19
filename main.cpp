#include "grid.h"
#include "robot.h"
#include "parser.h"

#include <boost/function.hpp>
#include <boost/bind.hpp>

#include <iostream>
#include <fstream>

using namespace ToyRobot;

const int c_GridDefaultSizeX = 4;  // start counting from 0
const int c_GridDefaultSizeY = 4;

int main (int argc, char *argv[])
{
    try
    {
        //grid
        // could use boost program options to allow grid size
        Grid grid = Grid( c_GridDefaultSizeX, c_GridDefaultSizeY );

        //robot
        Robot robot = Robot( grid );

        //function pointer from parser/lexer
        boost::function< void( std::shared_ptr< Command >& ) > doExecuteFunction( boost::bind( &Robot::DoExecute, robot, _1 ) );

        Parser parser = Parser( doExecuteFunction );

        if( 2 <= argc )
        {
            //load robot commands from file - assuming first arg is filename
            //can be extended with boost program options
            std::ifstream commandFile( argv[ 1 ] );
            if( commandFile.is_open() )
            {
                while( commandFile.good() )
                {
                    std::string currentLine;
                    std::getline( commandFile, currentLine );
                    parser.ParseInput( currentLine );
                }
            }
        }
        else
        {
            //get commands from command line
        }
    }
    catch( ... )
    {
        std::cerr << "Caught unknown exception" << std::endl;
        return 1;
    }
    return 0;
}
