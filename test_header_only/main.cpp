#define BOOST_TEST_MAIN test_robot_suite
#include <boost/test/included/unit_test.hpp>

//single file for boost test header only

#include <command.h>
#include <coordinates.h>
#include <direction.h>
#include <grid.h>
#include <move_command.h>
#include <parser.h>
#include <place_command.h>
#include <position.h>
#include <report_command.h>
#include <rotate_command.h>
#include <rotation.h>

#include <functional>
#include <string>

using namespace ToyRobot;

namespace UnitTestToyRobot
{

//////////////////////////////
// Fixtures
//////////////////////////////

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

struct GridFixture
{
    const int c_gridDefaultX = 7;
    const int c_gridDefaultY = 8;

    GridFixture()
    {
        grid = new Grid( c_gridDefaultX, c_gridDefaultY );
    }

    ~GridFixture()
    {
        delete grid;
    }
    Grid* grid;
};

struct MoveCommandFixture
{

    const int c_moveGridDefaultX = 4;
    const int c_moveGridDefaultY = 4;

    MoveCommandFixture() :
        position( Coordinates( 0, 0 ), Direction( Direction::NORTH ) ),
        grid( c_moveGridDefaultX, c_moveGridDefaultY )
    {
        moveCommand = new MoveCommand();
    }

    ~MoveCommandFixture()
    {
        delete moveCommand;
    }

    Position position;
    Grid grid;
    MoveCommand* moveCommand;
};

struct ParserFixture
{
    const std::string c_invalidString = "not a command";
    const std::string c_moveString = "MOVE";
    const std::string c_moveStringCase = "mOve";
    const std::string c_leftString = "LEFT";
    const std::string c_rightString = "RIGHT";
    const std::string c_reportString = "REPORT";
    const std::string c_placeString = "PLACE 1,2,EAST";
    const std::string c_placeStringExtra = "PLACE 1,2,SOUTH,AUSTRALIA";
    const std::string c_placeStringIncomplete = "PLACE 1,1";

    ParserFixture() :
        isValidCommand( false )
    {
        std::function< void( std::shared_ptr< Command >& ) > commandFunctor( std::bind( &ParserFixture::DoExecute, this, std::placeholders::_1 ) );
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

struct ReportCommandFixture
{
    const int c_reportGridDefaultX = 4;
    const int c_reportGridDefaultY = 4;

    ReportCommandFixture() :
        position(),
        grid( c_reportGridDefaultX, c_reportGridDefaultY )
    {
        reportCommand = new ReportCommand();
    }

    ~ReportCommandFixture()
    {
        delete reportCommand;
    }

    Position position;
    Grid grid;
    ReportCommand* reportCommand;
};

struct RotateCommandFixture
{
    const int c_rotateGridDefaultX = 4;
    const int c_rotateGridDefaultY = 4;
    
    RotateCommandFixture() :
        position( Coordinates( 0, 0 ), Direction( Direction::NORTH ) ),
        grid( c_rotateGridDefaultX, c_rotateGridDefaultY )
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


BOOST_FIXTURE_TEST_SUITE( coordinates_tests, CoordinatesFixture )

BOOST_AUTO_TEST_CASE( initialisation )
{
    int expectedValue = -1 ;
    BOOST_CHECK_EQUAL( coordinates->GetX(), expectedValue );
    BOOST_CHECK_EQUAL( coordinates->GetY(), expectedValue );
}

BOOST_AUTO_TEST_CASE( initialisation2 )
{
    int xValue = 3;
    int yValue = 5;
    Coordinates coords = Coordinates( 3, 5 );
    BOOST_CHECK_EQUAL( coords.GetX(), xValue );
    BOOST_CHECK_EQUAL( coords.GetY(), yValue );
}

BOOST_AUTO_TEST_CASE( set_value )
{
    int xValue = 1;
    int yValue = 4;
    coordinates->SetX( 1 );
    coordinates->SetY( 4 );
    BOOST_CHECK_EQUAL( coordinates->GetX(), xValue );
    BOOST_CHECK_EQUAL( coordinates->GetY(), yValue );
}

BOOST_AUTO_TEST_CASE( set_value2 )
{
    int xValue = 2;
    int yValue = 6;
    coordinates->SetCoordinates( 2, 6 );
    BOOST_CHECK_EQUAL( coordinates->GetX(), xValue );
    BOOST_CHECK_EQUAL( coordinates->GetY(), yValue );
}

BOOST_AUTO_TEST_SUITE_END()


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


BOOST_FIXTURE_TEST_SUITE( grid_tests, GridFixture )

BOOST_AUTO_TEST_CASE( initialisation )
{
    BOOST_CHECK_EQUAL( grid->GetX(), c_gridDefaultX );
    BOOST_CHECK_EQUAL( grid->GetY(), c_gridDefaultY );
}

BOOST_AUTO_TEST_CASE( on_grid_pass )
{
    BOOST_CHECK( grid->OnGrid( c_gridDefaultX, c_gridDefaultY ) );
    BOOST_CHECK( grid->OnGrid( 0, 0 ) );
    BOOST_CHECK( grid->OnGrid( 0, c_gridDefaultY ) );
    BOOST_CHECK( grid->OnGrid( c_gridDefaultX, 0 ) );
}

BOOST_AUTO_TEST_CASE( on_grid_fail )
{
    bool expectedValue = false;
    BOOST_CHECK_EQUAL( grid->OnGrid( c_gridDefaultX + 1, c_gridDefaultY + 1 ), expectedValue );
    BOOST_CHECK_EQUAL( grid->OnGrid( c_gridDefaultX + 1, c_gridDefaultY ), expectedValue );
    BOOST_CHECK_EQUAL( grid->OnGrid( c_gridDefaultX, c_gridDefaultY + 1 ), expectedValue );
    BOOST_CHECK_EQUAL( grid->OnGrid( -1, -1 ), expectedValue );
    BOOST_CHECK_EQUAL( grid->OnGrid( -1, c_gridDefaultY ), expectedValue );
    BOOST_CHECK_EQUAL( grid->OnGrid( c_gridDefaultX, -1 ), expectedValue );
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_FIXTURE_TEST_SUITE( move_tests, MoveCommandFixture )

BOOST_AUTO_TEST_CASE( move_normal_init )
{
    Coordinates expectedCoordinates( 0, 1 );
    Direction::DirectionEnum expectedDirection = Direction::NORTH;
    Position newPosition = moveCommand->Execute( position, grid );

    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( move_normal_set_direction_valid )
{
    position.SetDirection( Direction( Direction::EAST ) );
    Coordinates expectedCoordinates( 1, 0 );
    Direction::DirectionEnum expectedDirection = Direction::EAST;
    Position newPosition = moveCommand->Execute( position, grid );

    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( move_normal_set_direction_invalid )
{
    position.SetDirection( Direction( Direction::WEST ) );
    Coordinates expectedCoordinates( 0, 0 );
    Direction::DirectionEnum expectedDirection = Direction::WEST;
    Position newPosition = moveCommand->Execute( position, grid );

    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );

    BOOST_CHECK_EQUAL( position.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( position.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( position.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( move_normal_set_coordinates_valid )
{
    position.SetCoordinates( Coordinates( 3, 3 ) );
    Coordinates expectedCoordinates( 3, 4 );
    Direction::DirectionEnum expectedDirection = Direction::NORTH;
    Position newPosition = moveCommand->Execute( position, grid );

    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( move_normal_set_coordinates_invalid )
{
    position.SetCoordinates( Coordinates( 4, 0 ) );
    position.SetDirection( Direction( Direction::SOUTH ) );
    Coordinates expectedCoordinates( 4, 0 );
    Direction::DirectionEnum expectedDirection = Direction::SOUTH;
    Position newPosition = moveCommand->Execute( position, grid );

    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );

    BOOST_CHECK_EQUAL( position.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( position.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( position.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_SUITE_END()


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



BOOST_AUTO_TEST_SUITE( place_tests )

BOOST_AUTO_TEST_CASE( place_valid )
{
    Position position;
    position.SetCoordinates( Coordinates( 3, 3 ) );
    position.SetDirection( Direction( Direction::EAST ) );
    PlaceCommand placeCommand = PlaceCommand( position );

    Coordinates expectedCoordinates( 3, 3 );
    Direction::DirectionEnum expectedDirection = Direction::EAST;
    Position newPosition = placeCommand.Execute( position, Grid( 4, 4 ) );

    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );
    BOOST_CHECK_EQUAL( position.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( position.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( position.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( place_invalid_direction )
{
    Position position;
    position.SetCoordinates( Coordinates( 3, 3 ) );
    PlaceCommand placeCommand = PlaceCommand( position );

    Coordinates expectedCoordinates( -1, -1 );
    Direction::DirectionEnum expectedDirection = Direction::INVALID;
    Position newPosition = placeCommand.Execute( position, Grid( 4, 4 ) );

    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( place_invalid_coordinates_beyond )
{
    Position position;
    position.SetCoordinates( Coordinates( -1, 0 ) );
    position.SetDirection( Direction( Direction::WEST ) );
    PlaceCommand placeCommand = PlaceCommand( position );

    Coordinates expectedCoordinates( -1, -1 );
    Direction::DirectionEnum expectedDirection = Direction::INVALID;
    Position newPosition = placeCommand.Execute( position, Grid( 4, 4 ) );

    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_CASE( place_invalid_coordinates_above )
{
    Position position;
    position.SetCoordinates( Coordinates( 11, 0 ) );
    position.SetDirection( Direction( Direction::WEST ) );
    PlaceCommand placeCommand = PlaceCommand( position );

    Coordinates expectedCoordinates( -1, -1 );
    Direction::DirectionEnum expectedDirection = Direction::INVALID;
    Position newPosition = placeCommand.Execute( position, Grid( 4, 4 ) );

    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_FIXTURE_TEST_SUITE( position_test_suite, PositionFixture )

BOOST_AUTO_TEST_CASE( initialisation )
{
    Direction::DirectionEnum expectedDirection = Direction::INVALID;
    Coordinates expectedCoordinates;
    BOOST_CHECK_EQUAL( position->GetDirection().GetDirection(), expectedDirection );
    BOOST_CHECK_EQUAL( position->GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( position->GetCoordinates().GetY(), expectedCoordinates.GetY() );
}

BOOST_AUTO_TEST_CASE( initialisation2 )
{
    Direction::DirectionEnum expectedDirection = Direction::WEST;
    Coordinates expectedCoordinates( 1, 1 );
    Position pos = Position( Coordinates( 1, 1 ), Direction( Direction::WEST ) );
    BOOST_CHECK_EQUAL( pos.GetDirection().GetDirection(), expectedDirection );
    BOOST_CHECK_EQUAL( pos.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( pos.GetCoordinates().GetY(), expectedCoordinates.GetY() );
}

BOOST_AUTO_TEST_CASE( position_set_coordinates )
{
    Direction::DirectionEnum expectedDirection = Direction::INVALID;
    Coordinates expectedCoordinates( -3 , -4 );
    position->SetCoordinates( Coordinates( -3, -4 ) );
    BOOST_CHECK_EQUAL( position->GetDirection().GetDirection(), expectedDirection );
    BOOST_CHECK_EQUAL( position->GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( position->GetCoordinates().GetY(), expectedCoordinates.GetY() );
}

BOOST_AUTO_TEST_CASE( position_set_direction )
{
    Direction::DirectionEnum expectedDirection = Direction::SOUTH;
    Coordinates expectedCoordinates;
    position->SetDirection( Direction( Direction::SOUTH ) );
    BOOST_CHECK_EQUAL( position->GetDirection().GetDirection(), expectedDirection );
    BOOST_CHECK_EQUAL( position->GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( position->GetCoordinates().GetY(), expectedCoordinates.GetY() );
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_FIXTURE_TEST_SUITE( report_tests, ReportCommandFixture )

BOOST_AUTO_TEST_CASE( report )
{
    position.SetCoordinates( Coordinates( 3, 3 ) );
    position.SetDirection( Direction( Direction::EAST ) );
    Coordinates expectedCoordinates( 3, 3 );
    Direction::DirectionEnum expectedDirection = Direction::EAST;
    Position newPosition = reportCommand->Execute(position, grid);

    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( newPosition.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( newPosition.GetDirection().GetDirection(), expectedDirection );
    BOOST_CHECK_EQUAL( position.GetCoordinates().GetX(), expectedCoordinates.GetX() );
    BOOST_CHECK_EQUAL( position.GetCoordinates().GetY(), expectedCoordinates.GetY() );
    BOOST_CHECK_EQUAL( position.GetDirection().GetDirection(), expectedDirection );
}

BOOST_AUTO_TEST_SUITE_END()


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


BOOST_AUTO_TEST_SUITE( test_rotation )

BOOST_AUTO_TEST_CASE( rotation_left_to_string_member )
{
    Rotation rotation;
    rotation.m_rotation = Rotation::LEFT;
    std::string expectedValue = "LEFT";
    BOOST_CHECK_EQUAL( rotation.ToString(), expectedValue );
}

BOOST_AUTO_TEST_CASE( rotation_right_to_string_member )
{
    Rotation rotation;
    rotation.m_rotation = Rotation::RIGHT;
    std::string expectedValue = "RIGHT";
    BOOST_CHECK_EQUAL( rotation.ToString(), expectedValue );
}

BOOST_AUTO_TEST_CASE( rotation_invalid_to_string_member )
{
    Rotation rotation;
    rotation.m_rotation = Rotation::INVALID;
    std::string expectedValue = "INVALID";
    BOOST_CHECK_EQUAL( rotation.ToString(), expectedValue );
}

BOOST_AUTO_TEST_CASE( rotation_left_to_string_arg )
{
    std::string expectedValue = "LEFT";
    BOOST_CHECK_EQUAL( Rotation::ToString( Rotation::LEFT ), expectedValue );
}

BOOST_AUTO_TEST_CASE( rotation_right_to_string_arg )
{
    std::string expectedValue = "RIGHT";
    BOOST_CHECK_EQUAL( Rotation::ToString( Rotation::RIGHT ), expectedValue );
}

BOOST_AUTO_TEST_CASE( rotation_invalid_to_string_arg )
{
    std::string expectedValue = "INVALID";
    BOOST_CHECK_EQUAL( Rotation::ToString( Rotation::INVALID ), expectedValue );
}

BOOST_AUTO_TEST_SUITE_END()

}
