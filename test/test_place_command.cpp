#ifndef UT_TOYROBOT_PLACE_COMMAND_H
#define UT_TOYROBOT_PLACE_COMMAND_H

#include <boost/test/unit_test.hpp>

#include "../src/coordinates.h"
#include "../src/direction.h"
#include "../src/grid.h"
#include "../src/place_command.h"
#include "../src/position.h"

using namespace ToyRobot;

namespace UnitTestToyRobot
{

const int c_defaultX = 5;
const int c_defaultY = 5;

struct PlaceCommandFixture
{
    PlaceCommandFixture()
    {
        //init the command here?
        int x = c_defaultX;
        int y = c_defaultY;
        position = new Position( Coordinates(), Direction() );
        grid = new Grid( x, y );
        placeCommand = new PlaceCommand();
    }

    ~PlaceCommandFixture()
    {
        delete position;
        delete grid;
        delete placeCommand;
    }

    ToyRobot::Position* position;
    ToyRobot::Grid* grid;
    ToyRobot::PlaceCommand* placeCommand;
}

BOOST_FIXTURE_TEST_SUITE( place_tests, PlaceCommandFixture )

BOOST_AUTO_TEST_CASE( place_valid )
{
    position->SetCoordinates( Coordinates( 3, 3 ) );
    position->SetDirection( Direction( Direction::EAST ) );
    Coordinates expectedCoordinates( 3, 3 );
    Direction expectedDirection( Direction::EAST );
    Position newPosition = placeCommand->Execute( position, grid );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates() , expectedCoordinates );
    BOOST_CHECK_EQUAL( newPosition.GetDirection(), expectedDirection );
    BOOST_CHECK_EQUAL( position.GetCoordinates() , expectedCoordinates );
    BOOST_CHECK_EQUAL( position.GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( place_invalid_direction )
{
    position->SetCoordinates( Coordinates( 3, 3 ) );
    Coordinates expectedCoordinates( 0, 0 );
    Direction expectedDirection( Direction::INVALID );
    Position newPosition = placeCommand->Execute( position, grid );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates() , expectedCoordinates );
    BOOST_CHECK_EQUAL( newPosition.GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( place_invalid_coordinates )
{
    position->SetCoordinates( Coordinates( -1, 0 ) );
    position->SetDirection( Direction( Direction::WEST ) );
    Coordinates expectedCoordinates( 0, 0 );
    Direction expectedDirection( Direction::INVALID );
    Position newPosition = placeCommand->Execute( position, grid );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates() , expectedCoordinates );
    BOOST_CHECK_EQUAL( newPosition.GetDirection(), expectedDirection );
}

//place already placed? need to check validity of command


BOOST_AUTO_TEST_SUITE_END()

}
#endif
