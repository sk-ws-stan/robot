#ifndef UT_TOYROBOT_ROTATE_COMMAND_H
#define UT_TOYROBOT_ROTATE_COMMAND_H

#include <coordinates.h>
#include <direction.h>
#include <grid.h>
#include <rotate_command.h>
#include <position.h>

#include <boost/test/unit_test.hpp>

using namespace ToyRobot;

namespace UnitTestToyRobot
{

const int c_defaultX = 4;
const int c_defaultY = 4;

struct RotateCommandFixture
{
    RotateCommandFixture() :
        position( Coordinates( 0, 0 ), Direction( Direction::NORTH ) ),
        grid( c_defaultX, c_defaultY )
    {
        rotation.m_rotation = Rotation::LEFT;
        rotateCommand = new RotateCommand( rotation );
    }

    ~RotateCommandFixture()
    {
        delete rotateCommand;
    }

    Position position;
    Grid grid;
    Rotation rotation;
    RotateCommand* rotateCommand;
};

BOOST_FIXTURE_TEST_SUITE( rotate_tests, RotateCommandFixture )

BOOST_AUTO_TEST_CASE( rotate_left )
{
    Coordinates expectedCoordinates( 0, 0 );
    Direction::DirectionEnum expectedDirection = Direction::WEST;
    Position newPosition = rotateCommand->Execute( position, grid );

    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( rotate_right )
{
    Coordinates expectedCoordinates( 0, 0 );
    Direction::DirectionEnum expectedDirection = Direction::EAST;
    rotation.m_rotation = Rotation::RIGHT;
    RotateCommand rotCommand = RotateCommand( rotation );
    Position newPosition = rotCommand.Execute( position, grid );

    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( rotate_invalid )
{
    Coordinates expectedCoordinates( 0, 0 );
    Direction::DirectionEnum expectedDirection = Direction::NORTH;
    rotation.m_rotation = Rotation::INVALID;
    RotateCommand rotCommand = RotateCommand(rotation);
    Position newPosition = rotCommand.Execute(position, grid);

    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_SUITE_END()

}
#endif
