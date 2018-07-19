#ifndef UT_TOYROBOT_PARSER_H
#define UT_TOYROBOT_PARSER_H

#include <command.h>
#include <parser.h>

#include <boost/test/unit_test.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>

#include <string>

using namespace ToyRobot;

namespace UnitTestToyRobot
{

const std::string c_invalidString( "not a command" );
const std::string c_moveString( "MOVE" );
const std::string c_moveStringCase( "mOve" );
const std::string c_leftString( "LEFT" );
const std::string c_rightString( "RIGHT" );
const std::string c_reportString( "REPORT" );
const std::string c_placeString( "PLACE 1,2,EAST" );
const std::string c_placeStringExtra( "PLACE 1,2,SOUTH,AUSTRALIA" );
const std::string c_placeStringIncomplete( "PLACE 1,1" );

struct ParserFixture
{
    ParserFixture() :
        isValidCommand( false )
    {
        boost::function< void( std::shared_ptr< Command >& ) > commandFunctor( boost::bind( &ParserFixture::DoExecute, this, _1 ) );
        parser = new Parser( commandFunctor );
    }

    ~ParserFixture()
    {
        delete parser;
    }

    void DoExecute( std::shared_ptr< Command > command )
    {
        isValidCommand = true;
    }

    bool isValidCommand;
    Parser* parser;
};

BOOST_FIXTURE_TEST_SUITE( parser_tests, ParserFixture )

BOOST_AUTO_TEST_CASE( test_invalid )
{
    parser->ParseInput( c_invalidString );
    bool expectedValue( false );
    BOOST_CHECK_EQUAL( isValidCommand, expectedValue );
}

BOOST_AUTO_TEST_CASE( test_move )
{
    parser->ParseInput( c_moveString );
    BOOST_CHECK( isValidCommand );
}

BOOST_AUTO_TEST_CASE( test_case )
{
    parser->ParseInput( c_moveStringCase );
    BOOST_CHECK( isValidCommand );
}

BOOST_AUTO_TEST_CASE( test_left )
{
    parser->ParseInput( c_leftString );
    BOOST_CHECK( isValidCommand );
}

BOOST_AUTO_TEST_CASE( test_right )
{
    parser->ParseInput( c_rightString );
    BOOST_CHECK( isValidCommand );
}

BOOST_AUTO_TEST_CASE( test_report )
{
    parser->ParseInput( c_reportString );
    BOOST_CHECK( isValidCommand );
}

BOOST_AUTO_TEST_CASE( test_place )
{
    parser->ParseInput( c_placeString );
    BOOST_CHECK( isValidCommand );
}

BOOST_AUTO_TEST_CASE( test_place_extra )
{
    parser->ParseInput( c_placeStringExtra );
    bool expectedValue( false );
    BOOST_CHECK_EQUAL( isValidCommand, expectedValue );
}

BOOST_AUTO_TEST_CASE( test_place_incomplete )
{
    parser->ParseInput( c_placeStringIncomplete );
    bool expectedValue( false );
    BOOST_CHECK_EQUAL( isValidCommand, expectedValue );
}

BOOST_AUTO_TEST_SUITE_END()

}
#endif

