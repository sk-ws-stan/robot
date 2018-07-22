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

const int c_defaultX = 4;
const int c_defaultY = 4;

BOOST_AUTO_TEST_SUITE( place_tests )

BOOST_AUTO_TEST_CASE( place_valid )
{
    Position position;
    position.SetCoordinates( Coordinates( 3, 3 ) );
    position.SetDirection( Direction( Direction::EAST ) );
    PlaceCommand placeCommand = PlaceCommand( position );

    Coordinates expectedCoordinates( 3, 3 );
    Direction::DirectionEnum expectedDirection = Direction::EAST;
    Position newPosition = placeCommand.Execute( position, Grid( c_defaultX, c_defaultY ) );

    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );
    BOOST_CHECK_EQUAL( position.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( position.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( position.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( place_invalid_direction )
{
    Position position;
    position.SetCoordinates( Coordinates( 3, 3 ) );
    PlaceCommand placeCommand = PlaceCommand( position );

    Coordinates expectedCoordinates( -1, -1 );
    Direction::DirectionEnum expectedDirection = Direction::INVALID;
    Position newPosition = placeCommand.Execute( position, Grid( c_defaultX, c_defaultY ) );

    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( place_invalid_coordinates )
{
    Position position;
    position.SetCoordinates( Coordinates( -1, 0 ) );
    position.SetDirection( Direction( Direction::WEST ) );
    PlaceCommand placeCommand = PlaceCommand( position );

    Coordinates expectedCoordinates( -1, -1 );
    Direction::DirectionEnum expectedDirection = Direction::INVALID;
    Position newPosition = placeCommand.Execute( position, Grid( c_defaultX, c_defaultY ) );

    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_SUITE_END()

}
#endif
