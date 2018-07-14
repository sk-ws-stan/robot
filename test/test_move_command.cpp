#ifndef UT_TOYROBOT_MOVE_COMMAND_H
#define UT_TOYROBOT_MOVE_COMMAND_H

#include <boost/test/unit_test.hpp>

#include "../src/coordinates.h"
#include "../src/direction.h"
#include "../src/grid.h"
#include "../src/move_command.h"
#include "../src/position.h"

using namespace ToyRobot;

namespace UnitTestToyRobot
{

const int c_defaultX = 5;
const int c_defaultY = 5;

struct MoveCommandFixture
{
    MoveCommandFixture()
    {
        //init the command here?
        int x = c_defaultX;
        int y = c_defaultY;
        position = new Position( Coordinates(), Direction() );
        grid = new Grid( x, y );
        moveCommand = new MoveCommand();
    }

    ~MoveCommandFixture()
    {
        delete position;
        delete grid;
        delete moveCommand;
    }

    Position* position;
    Grid* grid;
    MoveCommand* moveCommand;
}

BOOST_FIXTURE_TEST_SUITE( move_tests, MoveCommandFixture )

BOOST_AUTO_TEST_CASE( move_normal_init )
{
    Coordinates expectedCoordinates( 0, 1 );
    Direction expectedDirection( Direction::NORTH );
    Position newPosition = moveCommand->Execute( position, grid );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates() , expectedCoordinates );
    BOOST_CHECK_EQUAL( newPosition.GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( move_normal_set_direction_valid )
{
    position->SetDirection( Direction( Direction::EAST ) );
    Coordinates expectedCoordinates( 1, 0 );
    Direction expectedDirection( Direction::EAST );
    Position newPosition = moveCommand->Execute( position, grid );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates() , expectedCoordinates );
    BOOST_CHECK_EQUAL( newPosition.GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( move_normal_set_direction_invalid )
{
    position->SetDirection( Direction( Direction::WEST ) );
    Coordinates expectedCoordinates( 0, 0 );
    Direction expectedDirection( Direction::WEST );
    Position newPosition = moveCommand->Execute( position, grid );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates() , expectedCoordinates );
    BOOST_CHECK_EQUAL( newPosition.GetDirection(), expectedDirection );
    BOOST_CHECK_EQUAL( position.GetCoordinates() , expectedCoordinates );
    BOOST_CHECK_EQUAL( position.GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( move_normal_set_coordinates_valid )
{
    position->SetCoordinates( Coordinates( 3, 3 ) );
    Coordinates expectedCoordinates( 3, 4 );
    Direction expectedDirection( Direction::NORTH );
    Position newPosition = moveCommand->Execute( position, grid );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates() , expectedCoordinates );
    BOOST_CHECK_EQUAL( newPosition.GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( move_normal_set_coordinates_invalid )
{
    position->SetCoordinates( Coordinates( 5, 0 ) );
    Coordinates expectedCoordinates( 5, 0 );
    Direction expectedDirection( Direction::SOUTH );
    Position newPosition = moveCommand->Execute( position, grid );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates() , expectedCoordinates );
    BOOST_CHECK_EQUAL( newPosition.GetDirection(), expectedDirection );
    BOOST_CHECK_EQUAL( position.GetCoordinates() , expectedCoordinates );
    BOOST_CHECK_EQUAL( position.GetDirection(), expectedDirection );
}


BOOST_AUTO_TEST_SUITE_END()

}
#endif
