#ifndef UT_TOYROBOT_REPORT_COMMAND_H
#define UT_TOYROBOT_REPORT_COMMAND_H

#include <coordinates.h>
#include <direction.h>
#include <grid.h>
#include <report_command.h>
#include <position.h>

#include <boost/test/unit_test.hpp>

using namespace ToyRobot;

namespace UnitTestToyRobot
{

const int c_defaultX = 5;
const int c_defaultY = 5;

struct ReportCommandFixture
{
    ReportCommandFixture() :
        position(),
        grid( c_defaultX, c_defaultY )
    {
        reportCommand = new ReportCommand();
    }

    ~ReportCommandFixture()
    {
        delete reportCommand;
    }

    Position position;
    Grid grid;
    ReportCommand* reportCommand;
};

BOOST_FIXTURE_TEST_SUITE( report_tests, ReportCommandFixture )

BOOST_AUTO_TEST_CASE( report )
{
    position.SetCoordinates( Coordinates( 3, 3 ) );
    position.SetDirection( Direction( Direction::EAST ) );
    Coordinates expectedCoordinates( 3, 3 );
    Direction::DirectionEnum expectedDirection = Direction::EAST;
    Position newPosition = reportCommand->Execute( position, grid );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );
    BOOST_CHECK_EQUAL( position.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( position.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( position.GetDirection().GetDirection(), expectedDirection );
}

//report output test case?


BOOST_AUTO_TEST_SUITE_END()

}
#endif
