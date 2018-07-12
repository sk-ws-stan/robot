#ifndef UT_TOYROBOT_GRID_H
#define UT_TOYROBOT_GRID_H

#include <boost/test/unit_test.hpp>

#include "../src/move_command.h"

namespace UnitTestToyRobot
{

struct MoveCommandFixture
{
    MoveCommandFixture()
    {
        //init the command here?
    }

    ~MoveCommandFixture()
    {
        delete moveCommand;
        delete position;
        delete grid;
    }

    ToyRobot::MoveCommand* moveCommand;
    ToyRobot::Position* position;
    ToyRobot::Grid* grid;
}

BOOST_FIXTURE_TEST_SUITE( move_tests, MoveCommandFixture )

BOOST_AUTO_TEST_CASE( move_normal )
{
    BOOST_CHECK_EQUAL( grid.GetX(), defaultX );
    BOOST_CHECK_EQUAL( grid.GetY(), defaultY );
}

BOOST_AUTO_TEST_CASE( move_denied )
{
    BOOST_CHECK( grid.OnGrid( defaultX, defaultY  );
    BOOST_CHECK( grid.OnGrid( 0, 0  );
    BOOST_CHECK( grid.OnGrid( 0, defaultY );
    BOOST_CHECK( grid.OnGrid( defaultX, 0 );
}


BOOST_AUTO_TEST_SUITE_END()

}
#endif
