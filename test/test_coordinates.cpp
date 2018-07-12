#ifndef UT_TOYROBOT_COORDINATES_H
#define UT_TOYROBOT_COORDINATES_H

#include <boost/test/unit_test.hpp>

#include "../src/coordinates.h"

namespace UnitTestToyRobot
{

struct CoordinatesFixture
{
    CoordinatesFixture()
    {
        coordinates = new Coordinates();
    }

    ~CoordinatesFixture()
    {
        delete coordinates;
    }

    Coordinates* coordinates;
};

BOOST_FEATURE_TEST_SUITE( coordinates_tests, CoordinatesFixture )

BOOST_AUTO_TEST_CASE( initialisation )
{
    int expectedValue = -1 ;
    BOOST_CHECK_EQUAL( coordinates.getX(), expectedValue );
    BOOST_CHECK_EQUAL( coordinates.getY(), expectedValue );
}

BOOST_AUTO_TEST_CASE( initialisation2 )
{
    int xValue = 3;
    int yValue = 5;
    Coordinates coords( 3, 5 );
    BOOST_CHECK_EQUAL( coords.GetX(), xValue );
    BOOST_CHECK_EQUAL( coords.GetY(), yValue );
}

BOOST_AUTO_TEST_CASE( set_value )
{
    int xValue = 1;
    int yValue = 4;
    coordinates.SetX( 1 );
    coordinates.SetY( 4 );
    BOOST_CHECK_EQUAL( coordinates.GetX(), xValue );
    BOOST_CHECK_EQUAL( coordinates.GetY(), yValue );
}

BOOST_AUTO_TEST_CASE( set_value2 )
{
    int xValue = 2;
    int yValue = 6;
    coordinates.SetCoordinates( 2, 6 );
    BOOST_CHECK_EQUAL( coordinates.GetX(), xValue );
    BOOST_CHECK_EQUAL( coordinates.GetY(), yValue );
}

BOOST_AUTO_TEST_SUITE_END()

}
#endif
