#ifndef UT_TOYROBOT_PLACE_COMMAND_H
#define UT_TOYROBOT_PLACE_COMMAND_H

#include <coordinates.h>
#include <direction.h>
#include <grid.h>
#include <place_command.h>
#include <position.h>

#include <boost/test/unit_test.hpp>

using namespace ToyRobot;

namespace UnitTestToyRobot
{

const int c_defaultX = 5;
const int c_defaultY = 5;

struct PlaceCommandFixture
{
    PlaceCommandFixture() :
        position(),
        grid( c_defaultX, c_defaultY )
    {
        placeCommand = new PlaceCommand();
    }

    ~PlaceCommandFixture()
    {
        delete placeCommand;
    }

    Position position;
    Grid grid;
    PlaceCommand* placeCommand;
};

BOOST_FIXTURE_TEST_SUITE( place_tests, PlaceCommandFixture )

BOOST_AUTO_TEST_CASE( place_valid )
{
    position.SetCoordinates( Coordinates( 3, 3 ) );
    position.SetDirection( Direction( Direction::EAST ) );
    Coordinates expectedCoordinates( 3, 3 );
    Direction::DirectionEnum expectedDirection = Direction::EAST;
    Position newPosition = placeCommand->Execute( position, grid );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );
    BOOST_CHECK_EQUAL( position.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( position.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( position.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( place_invalid_direction )
{
    position.SetCoordinates( Coordinates( 3, 3 ) );
    Coordinates expectedCoordinates( -1, -1 );
    Direction::DirectionEnum expectedDirection = Direction::INVALID;
    Position newPosition = placeCommand->Execute( position, grid );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( place_invalid_coordinates )
{
    position.SetCoordinates( Coordinates( -1, 0 ) );
    position.SetDirection( Direction( Direction::WEST ) );
    Coordinates expectedCoordinates( -1, -1 );
    Direction::DirectionEnum expectedDirection = Direction::INVALID;
    Position newPosition = placeCommand->Execute( position, grid );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );
}

//place already placed? need to check validity of command


BOOST_AUTO_TEST_SUITE_END()

}
#endif
