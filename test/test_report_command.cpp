#ifndef UT_TOYROBOT_REPORT_COMMAND_H
#define UT_TOYROBOT_REPORT_COMMAND_H

#include <coordinates.h>
#include <direction.h>
#include <grid.h>
#include <report_command.h>
#include <position.h>

#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

#include <iostream>

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

//this redirects std::cout to the boost::output_test_stream
//https://www.boost.org/doc/libs/1_67_0/libs/test/doc/html/boost_test/testing_tools/output_stream_testing.html
struct CoutRedirect
{
    CoutRedirect( std::streambuf* newBuffer ) :
        oldBuffer( std::cout.rdbuf( newBuffer ) )
    {
    }

    ~CoutRedirect()
    {
        std::cout.rdbuf( oldBuffer );
    }
private:
    std::streambuf* oldBuffer;
};

BOOST_FIXTURE_TEST_SUITE( report_tests, ReportCommandFixture )

BOOST_AUTO_TEST_CASE( report )
{
    position.SetCoordinates( Coordinates( 3, 3 ) );
    position.SetDirection( Direction( Direction::EAST ) );
    Coordinates expectedCoordinates( 3, 3 );
    Direction::DirectionEnum expectedDirection = Direction::EAST;
    std::string expectedOutput( "3,3,EAST\n" );
    Position newPosition;

    boost::test_tools::output_test_stream output;
    {
        CoutRedirect guard( output.rdbuf() );

        newPosition = reportCommand->Execute( position, grid );
    }
    BOOST_CHECK( output.is_equal( expectedOutput ) );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );
    BOOST_CHECK_EQUAL( position.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( position.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( position.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_SUITE_END()

}
#endif
