#ifndef UT_TOYROBOT_ROTATION_H
#define UT_TOYROBOT_ROTATION_H

#include <rotation.h>

#include <boost/test/unit_test.hpp>

#include <string>

using namespace ToyRobot;

namespace UtToyRobot
{

BOOST_AUTO_TEST_SUITE( test_rotation )

BOOST_AUTO_TEST_CASE( rotation_to_string_member )
{
    Rotation rotation;
    rotation.m_rotation = Rotation::LEFT;
    std::string expectedValue = "LEFT";
    BOOST_CHECK_EQUAL( rotation.ToString(), expectedValue );
}

BOOST_AUTO_TEST_CASE( rotation_to_string_arg )
{
    std::string expectedValue = "RIGHT";
    BOOST_CHECK_EQUAL( Rotation::ToString( Rotation::RIGHT ), expectedValue );
}

BOOST_AUTO_TEST_SUITE_END()

}
#endif

