#ifndef UT_TOYROBOT_REPORT_COMMAND_H
#define UT_TOYROBOT_REPORT_COMMAND_H

#include <boost/test/unit_test.hpp>

#include "../src/coordinates.h"
#include "../src/direction.h"
#include "../src/grid.h"
#include "../src/report_command.h"
#include "../src/position.h"

using namespace ToyRobot;

namespace UnitTestToyRobot
{

const int c_defaultX = 5;
const int c_defaultY = 5;

struct ReportCommandFixture
{
    ReportCommandFixture()
    {
        //init the command here?
        int x = c_defaultX;
        int y = c_defaultY;
        position = new Position( Coordinates(), Direction() );
        grid = new Grid( x, y );
        reportCommand = new ReportCommand();
    }

    ~ReportCommandFixture()
    {
        delete position;
        delete grid;
        delete reportCommand;
    }

    ToyRobot::Position* position;
    ToyRobot::Grid* grid;
    ToyRobot::ReportCommand* reportCommand;
}

BOOST_FIXTURE_TEST_SUITE( report_tests, reportCommandFixture )

BOOST_AUTO_TEST_CASE( report )
{
    position->SetCoordinates( Coordinates( 3, 3 ) );
    position->SetDirection( Direction( Direction::EAST ) );
    Coordinates expectedCoordinates( 3, 3 );
    Direction expectedDirection( Direction::EAST );
    Position newPosition = reportCommand->Execute( position, grid );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates() , expectedCoordinates );
    BOOST_CHECK_EQUAL( newPosition.GetDirection(), expectedDirection );
    BOOST_CHECK_EQUAL( position.GetCoordinates() , expectedCoordinates );
    BOOST_CHECK_EQUAL( position.GetDirection(), expectedDirection );
}

//report output test case?


BOOST_AUTO_TEST_SUITE_END()

}
#endif
