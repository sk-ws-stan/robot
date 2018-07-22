#ifndef UT_TOYROBOT_GRID_H
#define UT_TOYROBOT_GRID_H

//#include "../src/grid.h"
#include <grid.h>

#include <boost/test/unit_test.hpp>

using namespace ToyRobot;

namespace UnitTestToyRobot
{

const int c_defaultX = 7;
const int c_defaultY = 8;

struct GridFixture
{
    GridFixture()
    {
        grid = new Grid( c_defaultX, c_defaultY );
    }

    ~GridFixture()
    {
        delete grid;
    }
    Grid* grid;
};

BOOST_FIXTURE_TEST_SUITE( grid_tests, GridFixture )

BOOST_AUTO_TEST_CASE( initialisation )
{
    BOOST_CHECK_EQUAL( grid->GetX(), c_defaultX );
    BOOST_CHECK_EQUAL( grid->GetY(), c_defaultY );
}

BOOST_AUTO_TEST_CASE( on_grid_pass )
{
    BOOST_CHECK( grid->OnGrid( c_defaultX, c_defaultY ) );
    BOOST_CHECK( grid->OnGrid( 0, 0 ) );
    BOOST_CHECK( grid->OnGrid( 0, c_defaultY ) );
    BOOST_CHECK( grid->OnGrid( c_defaultX, 0 ) );
}

BOOST_AUTO_TEST_CASE( on_grid_fail )
{
    bool expectedValue = false;
    BOOST_CHECK_EQUAL( grid->OnGrid( c_defaultX + 1, c_defaultY + 1 ), expectedValue );
    BOOST_CHECK_EQUAL( grid->OnGrid( c_defaultX + 1, c_defaultY ), expectedValue );
    BOOST_CHECK_EQUAL( grid->OnGrid( c_defaultX, c_defaultY + 1 ), expectedValue );
    BOOST_CHECK_EQUAL( grid->OnGrid( -1, -1 ), expectedValue );
    BOOST_CHECK_EQUAL( grid->OnGrid( -1, c_defaultY ), expectedValue );
    BOOST_CHECK_EQUAL( grid->OnGrid( c_defaultX, -1 ), expectedValue );
}

BOOST_AUTO_TEST_SUITE_END()

}
#endif
