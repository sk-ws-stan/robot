#ifndef UT_TOYROBOT_TEST_POSITION_H
#define UT_TOYROBOT_TEST_POSITION_H

#include "../src/coordinates.h"
#include "../src/direction.h"
#include "../src/position.h"

#include <boost/test/unit_test.hpp>

using namespace ToyRobot;

namespace UtToyRobot
{

struct PositionFixture
{
    PositionFixture()
    {
        position = new Position();
    }
    ~PositionFixture()
    {
        delete position;
    }
    Position* position;
};

BOOST_FIXTURE_TEST_SUITE( position_test_suite, PositionFixture )

BOOST_AUTO_TEST_CASE( initialisation )
{
    Direction expectedDirection();
    Coordinates expectedCoordinates();
    BOOST_TEST_EQUAL( position->GetDirection(), expectedDirection );
    BOOST_TEST_EQUAL( position->GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_TEST_EQUAL( position->GetCoordinates().GetY(), expectedCoordinates.GetY() );
}

BOOST_AUTO_TEST_CASE( initialisation2 )
{
    Direction expectedDirection( Direction::WEST );
    Coordinates expectedCoordinates( 1, 1 );
    Position pos = Position( Coordinates( 1, 1 ), Direction( Direction::WEST ) );
    BOOST_TEST_EQUAL( pos.GetDirection(), expectedDirection );
    BOOST_TEST_EQUAL( pos.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_TEST_EQUAL( pos.GetCoordinates().GetY(), expectedCoordinates.GetY() );
}

BOOST_AUTO_TEST_CASE( position_set_coordinates )
{
    Direction expectedDirection();
    Coordinates expectedCoordinates( -3 , -4 );
    position->SetCoordinates( Coordinates( -3, -4 ) );
    BOOST_TEST_EQUAL( position->GetDirection(), expectedDirection );
    BOOST_TEST_EQUAL( position->GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_TEST_EQUAL( position->GetCoordinates().GetY(), expectedCoordinates.GetY() );
}

BOOST_AUTO_TEST_CASE( position_set_direction )
{
    Direction expectedDirection( Direction( Direction::SOUTH ) );
    Coordinates expectedCoordinates();
    position->SetDirection( Direction( Direction::SOUTH ) );
    BOOST_TEST_EQUAL( position->GetDirection(), expectedDirection );
    BOOST_TEST_EQUAL( position->GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_TEST_EQUAL( position->GetCoordinates().GetY(), expectedCoordinates.GetY() );
}

BOOST_AUTO_TEST_SUITE_END()

}
#endif

