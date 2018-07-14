#ifndef UT_TOYROBOT_DIRECTION_H
#define UT_TOYROBOT_DIRECTION_H

#include <boost/test/unit_test.hpp>

#include "../src/direction.h"

using namespace ToyRobot;

namespace UnitTestToyRobot
{

struct DirectionFixture
{
    DirectionFixture()
    {
        direction = new Direction();
    }

    ~DirectionFixture()
    {
        delete direction;
    }

    Direction* direction;
};

BOOST_FEATURE_TEST_SUITE( direction_tests, DirectionFixture )

BOOST_AUTO_TEST_CASE( initialisation )
{
    DirectionEnum expectedValue = Direction::INVALID;
    BOOST_CHECK_EQUAL( direction->GetDirection(), expectedValue );
}

BOOST_AUTO_TEST_CASE( initialisation2 )
{
    DirectionEnum value = Direction::NORTH;
    Direction dir( value );
    BOOST_CHECK_EQUAL( dir->GetDirection(), value );
}

BOOST_AUTO_TEST_CASE( set_value )
{
    DirectionEnum value = Direction::NORTH;
    direction->SetDirection( value );
    BOOST_CHECK_EQUAL( direction->GetDirection(), value );
}

BOOST_AUTO_TEST_CASE( to_string_member )
{
    direction->SetDirection( Direction::NORTH );
    std::string expectedValue( "NORTH" );
    BOOST_CHECK_EQUAL( direction->ToString(), expectedValue );

    direction->SetDirection( Direction::SOUTH );
    expectedValue = "SOUTH";
    BOOST_CHECK_EQUAL( direction->ToString(), expectedValue );

    direction->SetDirection( Direction::WEST );
    expectedValue = "WEST";
    BOOST_CHECK_EQUAL( direction->ToString(), expectedValue );

    direction->SetDirection( Direction::EAST );
    expectedValue = "EAST";
    BOOST_CHECK_EQUAL( direction->ToString(), expectedValue );
}

BOOST_AUTO_TEST_CASE( to_string_arg )
{
    std::string expectedValue( "NORTH" );
    BOOST_CHECK_EQUAL( Direction::ToString( Direction::NORTH ), expectedValue );

    expectedValue = "SOUTH";
    BOOST_CHECK_EQUAL( Direction::ToString( Direction::SOUTH ), expectedValue );

    expectedValue = "WEST";
    BOOST_CHECK_EQUAL( Direction::ToString( Direction::WEST ), expectedValue );

    expectedValue = "EAST";
    BOOST_CHECK_EQUAL( Direction::ToString( Direction::EAST ), expectedValue );
}

BOOST_AUTO_TEST_CASE( turn_left_valid )
{
    direction->SetDirection( Direction::SOUTH );
    direction->TurnLeft();
    Direction expectedValue( Direction::WEST );
    BOOST_CHECK_EQUAL( direction->GetDirection(), expectedValue );
}

BOOST_AUTO_TEST_CASE( turn_left_invalid )
{
    direction->SetDirection( Direction::INVALID );
    direction->TurnLeft();
    Direction expectedValue( Direction::INVALID );
    BOOST_CHECK_EQUAL( direction->GetDirection(), expectedValue );
}

BOOST_AUTO_TEST_CASE( turn_right_valid )
{
    direction->SetDirection( Direction::EAST );
    direction->TurnRight();
    Direction expectedValue( Direction::SOUTH );
    BOOST_CHECK_EQUAL( direction->GetDirection(), expectedValue );
}

BOOST_AUTO_TEST_CASE( turn_right_invalid )
{
    direction->SetDirection( Direction::INVALID );
    direction->TurnLeft();
    Direction expectedValue( Direction::INVALID );
    BOOST_CHECK_EQUAL( direction->GetDirection(), expectedValue );
}

BOOST_AUTO_TEST_SUITE_END()

}
#endif
