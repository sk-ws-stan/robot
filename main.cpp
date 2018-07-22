#include <command.h>
#include <grid.h>
#include <parser.h>
#include <robot.h>

#include <boost/bind.hpp>
#include <boost/function.hpp>

#include <fstream>
#include <iostream>

using namespace ToyRobot;

const int c_GridDefaultSizeX = 4;
const int c_GridDefaultSizeY = 4;

int main( int argc, char* argv[] )
{
    int returnValue = 0;

    try
    {
        //could use boost program options to allow custom grid size
        Grid grid = Grid( c_GridDefaultSizeX, c_GridDefaultSizeY );
        Robot robot = Robot( grid );
        //function pointer for parser
        boost::function< void( std::shared_ptr< Command >& ) > doExecuteFunction( boost::bind( &Robot::DoExecute, robot, _1 ) );

        Parser parser = Parser( doExecuteFunction );

        if( 2 <= argc )
        {
            std::cout << "Reading Commands from file " << argv[ 1 ] << "." << std::endl;
            //load robot commands from file - assuming first arg is filename
            //functionality could be extended with boost program options (e.g. help output)
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
            std::cout << "Reading Commands from console. Empty Command stops the ToyRobot." << std::endl;

            while( true )
            {
                std::string currentCommandLine;
                std::getline( std::cin, currentCommandLine );
                if( currentCommandLine.empty() )
                {
                    break;
                }
                parser.ParseInput( currentCommandLine );
            }
        }
    }
    catch( ... )
    {
        std::cerr << "Caught unknown exception" << std::endl;
        returnValue = 1;
    }
    return returnValue;
}
