#ifndef UT_TOYROBOT_DIRECTION_H
#define UT_TOYROBOT_DIRECTION_H

#include <direction.h>

#include <boost/test/unit_test.hpp>

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

BOOST_FIXTURE_TEST_SUITE( direction_tests, DirectionFixture )

BOOST_AUTO_TEST_CASE( initialisation )
{
    Direction::DirectionEnum expectedValue = Direction::INVALID;
    BOOST_CHECK_EQUAL( direction->GetDirection(), expectedValue );
}

BOOST_AUTO_TEST_CASE( initialisation2 )
{
    Direction::DirectionEnum value = Direction::NORTH;
    Direction dir( value );
    BOOST_CHECK_EQUAL( dir.GetDirection(), value );
}

BOOST_AUTO_TEST_CASE( initialisation3 )
{
    Direction dir( std::string( "NORTH" ) );
    Direction::DirectionEnum expectedValue = Direction::NORTH;
    BOOST_CHECK_EQUAL( dir.GetDirection(), expectedValue );
}

BOOST_AUTO_TEST_CASE( initialisation4 )
{
    Direction dir( std::string( "NAUGHT" ) );
    Direction::DirectionEnum expectedValue = Direction::INVALID;
    BOOST_CHECK_EQUAL( dir.GetDirection(), expectedValue );
}

BOOST_AUTO_TEST_CASE( set_value )
{
    Direction::DirectionEnum value = Direction::NORTH;
    direction->SetDirection( value );
    BOOST_CHECK_EQUAL( direction->GetDirection(), value );
}

BOOST_AUTO_TEST_CASE( to_string_member )
{
    std::string expectedValue( "INVALID" );
    BOOST_CHECK_EQUAL( direction->ToString(), expectedValue );

    direction->SetDirection( Direction::NORTH );
    expectedValue = "NORTH";
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

    expectedValue = "INVALID";
    BOOST_CHECK_EQUAL( Direction::ToString( Direction::INVALID ), expectedValue );
}

BOOST_AUTO_TEST_CASE( turn_left_valid_north )
{
    direction->SetDirection( Direction::NORTH );
    direction->TurnLeft();
    Direction::DirectionEnum expectedValue = Direction::WEST;
    BOOST_CHECK_EQUAL( direction->GetDirection(), expectedValue );
}

BOOST_AUTO_TEST_CASE( turn_left_valid_south )
{
    direction->SetDirection( Direction::SOUTH );
    direction->TurnLeft();
    Direction::DirectionEnum expectedValue = Direction::EAST;
    BOOST_CHECK_EQUAL( direction->GetDirection(), expectedValue );
}

BOOST_AUTO_TEST_CASE( turn_left_valid_east )
{
    direction->SetDirection( Direction::EAST );
    direction->TurnLeft();
    Direction::DirectionEnum expectedValue = Direction::NORTH;
    BOOST_CHECK_EQUAL( direction->GetDirection(), expectedValue );
}

BOOST_AUTO_TEST_CASE( turn_left_valid_west )
{
    direction->SetDirection( Direction::WEST );
    direction->TurnLeft();
    Direction::DirectionEnum expectedValue = Direction::SOUTH;
    BOOST_CHECK_EQUAL( direction->GetDirection(), expectedValue );
}

BOOST_AUTO_TEST_CASE( turn_left_invalid )
{
    direction->SetDirection( Direction::INVALID );
    direction->TurnLeft();
    Direction::DirectionEnum expectedValue = Direction::INVALID;
    BOOST_CHECK_EQUAL( direction->GetDirection(), expectedValue );
}

BOOST_AUTO_TEST_CASE( turn_right_valid_north )
{
    direction->SetDirection( Direction::NORTH );
    direction->TurnRight();
    Direction::DirectionEnum expectedValue = Direction::EAST;
    BOOST_CHECK_EQUAL( direction->GetDirection(), expectedValue );
}

BOOST_AUTO_TEST_CASE( turn_right_valid_south )
{
    direction->SetDirection( Direction::SOUTH );
    direction->TurnRight();
    Direction::DirectionEnum expectedValue = Direction::WEST;
    BOOST_CHECK_EQUAL( direction->GetDirection(), expectedValue );
}

BOOST_AUTO_TEST_CASE( turn_right_valid_east )
{
    direction->SetDirection( Direction::EAST );
    direction->TurnRight();
    Direction::DirectionEnum expectedValue = Direction::SOUTH;
    BOOST_CHECK_EQUAL( direction->GetDirection(), expectedValue );
}

BOOST_AUTO_TEST_CASE( turn_right_valid_west )
{
    direction->SetDirection( Direction::WEST );
    direction->TurnRight();
    Direction::DirectionEnum expectedValue = Direction::NORTH;
    BOOST_CHECK_EQUAL( direction->GetDirection(), expectedValue );
}

BOOST_AUTO_TEST_CASE( turn_right_invalid )
{
    direction->SetDirection( Direction::INVALID );
    direction->TurnLeft();
    Direction::DirectionEnum expectedValue = Direction::INVALID;
    BOOST_CHECK_EQUAL( direction->GetDirection(), expectedValue );
}

BOOST_AUTO_TEST_SUITE_END()

}
#endif
