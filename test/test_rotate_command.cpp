#ifndef UT_TOYROBOT_ROTATE_COMMAND_H
#define UT_TOYROBOT_ROTATE_COMMAND_H

#include <boost/test/unit_test.hpp>

#include "../src/coordinates.h"
#include "../src/direction.h"
#include "../src/grid.h"
#include "../src/rotate_command.h"
#include "../src/position.h"

using namespace ToyRobot;

namespace UnitTestToyRobot
{

const int c_defaultX = 5;
const int c_defaultY = 5;

struct RotateCommandFixture
{
    RotateCommandFixture()
    {
        //init the command here?
        int x = c_defaultX;
        int y = c_defaultY;
        position = new Position( Coordinates( 0, 0 ), Direction( Direction::EAST ) );
        grid = new Grid( x, y );
        rotateCommand = new RotateCommand( Rotation( Rotation::LEFT ) );
    }

    ~RotateCommandFixture()
    {
        delete position;
        delete grid;
        delete rotateCommand;
    }

    ToyRobot::Position* position;
    ToyRobot::Grid* grid;
    ToyRobot::RotateCommand* rotateCommand;
}

BOOST_FIXTURE_TEST_SUITE( rotate_tests, RotateCommandFixture )

BOOST_AUTO_TEST_CASE( rotate_left )
{
    Coordinates expectedCoordinates( 0, 0 );
    Direction expectedDirection( Direction::NORTH );
    Position newPosition = rotateCommand->Execute( position, grid );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates() , expectedCoordinates );
    BOOST_CHECK_EQUAL( newPosition.GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( rotate_right )
{
    Coordinates expectedCoordinates( 0, 0 );
    Direction expectedDirection( Direction::SOUTH );
    RotateCommand rotCommand = RotateCommand( Rotation::RIGHT );
    Position newPosition = rotCommand->Execute( position, grid );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates() , expectedCoordinates );
    BOOST_CHECK_EQUAL( newPosition.GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( rotate_invalid )
{
    Coordinates expectedCoordinates( 0, 0 );
    Direction expectedDirection( Direction::EAST );
    RotateCommand rotCommand = RotateCommand( Rotation::INVALID );
    Position newPosition = rotCommand->Execute( position, grid );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates() , expectedCoordinates );
    BOOST_CHECK_EQUAL( newPosition.GetDirection(), expectedDirection );
}

}
#endif
