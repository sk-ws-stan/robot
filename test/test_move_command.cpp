#ifndef UT_TOYROBOT_MOVE_COMMAND_H
#define UT_TOYROBOT_MOVE_COMMAND_H

#include <coordinates.h>
#include <direction.h>
#include <grid.h>
#include <move_command.h>
#include <position.h>

#include <boost/test/unit_test.hpp>

using namespace ToyRobot;

namespace UnitTestToyRobot
{

const int c_defaultX = 4;
const int c_defaultY = 4;

struct MoveCommandFixture
{
    MoveCommandFixture() :
        position( Coordinates( 0, 0 ), Direction( Direction::NORTH ) ),
        grid( c_defaultX, c_defaultY )
    {
        moveCommand = new MoveCommand();
    }

    ~MoveCommandFixture()
    {
        delete moveCommand;
    }

    Position position;
    Grid grid;
    MoveCommand* moveCommand;
};

BOOST_FIXTURE_TEST_SUITE( move_tests, MoveCommandFixture )

BOOST_AUTO_TEST_CASE( move_normal_init )
{
    Coordinates expectedCoordinates( 0, 1 );
    Direction::DirectionEnum expectedDirection = Direction::NORTH;
    Position newPosition = moveCommand->Execute( position, grid );

    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( move_normal_set_direction_valid )
{
    position.SetDirection( Direction( Direction::EAST ) );
    Coordinates expectedCoordinates( 1, 0 );
    Direction::DirectionEnum expectedDirection = Direction::EAST;
    Position newPosition = moveCommand->Execute( position, grid );

    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( move_normal_set_direction_invalid )
{
    position.SetDirection( Direction( Direction::WEST ) );
    Coordinates expectedCoordinates( 0, 0 );
    Direction::DirectionEnum expectedDirection = Direction::WEST;
    Position newPosition = moveCommand->Execute( position, grid );

    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );

    BOOST_CHECK_EQUAL( position.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( position.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( position.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( move_normal_set_coordinates_valid )
{
    position.SetCoordinates( Coordinates( 3, 3 ) );
    Coordinates expectedCoordinates( 3, 4 );
    Direction::DirectionEnum expectedDirection = Direction::NORTH;
    Position newPosition = moveCommand->Execute( position, grid );

    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( move_normal_set_coordinates_invalid )
{
    position.SetCoordinates( Coordinates( 4, 0 ) );
    position.SetDirection( Direction( Direction::SOUTH ) );
    Coordinates expectedCoordinates( 4, 0 );
    Direction::DirectionEnum expectedDirection = Direction::SOUTH;
    Position newPosition = moveCommand->Execute( position, grid );

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
