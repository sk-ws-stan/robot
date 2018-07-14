#ifndef UT_TOYROBOT_GRID_H
#define UT_TOYROBOT_GRID_H

#include <boost/test/unit_test.hpp>

#include "../src/grid.h"

using namespace ToyRobot;

namespace UnitTestToyRobot
{

struct GridFixture
{
    GridFixture()
    {
        defaultX = 7;
        defaultY = 8;
        grid = new Grid( defaultX, deafultY);
    }

    ~GridFixture()
    {
        delete grid;
    }
    int defaultX;
    int defaultY;
    Grid* grid;
};

BOOST_FEATURE_TEST_SUITE( grid_tests, GridFixture )

BOOST_AUTO_TEST_CASE( initialisation )
{
    BOOST_CHECK_EQUAL( grid.GetX(), defaultX );
    BOOST_CHECK_EQUAL( grid.GetY(), defaultY );
}

BOOST_AUTO_TEST_CASE( on_grid_pass )
{
    BOOST_CHECK( grid.OnGrid( defaultX, defaultY  );
    BOOST_CHECK( grid.OnGrid( 0, 0  );
    BOOST_CHECK( grid.OnGrid( 0, defaultY );
    BOOST_CHECK( grid.OnGrid( defaultX, 0 );
}

BOOST_AUTO_TEST_CASE( on_grid_fail )
{
    bool expectedValue = false;
    BOOST_CHECK_EQUAL( grid.OnGrid( defaultX + 1, defaultY + 1 ), expectedValue );
    BOOST_CHECK_EQUAL( grid.OnGrid( defaultX + 1, defaultY ), expectedValue );
    BOOST_CHECK_EQUAL( grid.OnGrid( defaultX, defaultY + 1 ), expectedValue );
    BOOST_CHECK_EQUAL( grid.OnGrid( -1, -1 ), expectedValue );
    BOOST_CHECK_EQUAL( grid.OnGrid( -1, defaultY ), expectedValue );
    BOOST_CHECK_EQUAL( grid.OnGrid( defaultX, -1 ), expectedValue );
}

BOOST_AUTO_TEST_SUITE_END()

}
#endif
