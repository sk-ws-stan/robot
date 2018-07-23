#include "direction.h"
#include "move_command.h"
#include "parser.h"
#include "place_command.h"
#include "report_command.h"
#include "rotate_command.h"

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

#include <string>
#include <vector>

namespace ToyRobot
{

Parser::Parser( const CommandFunctor& fct ) :
    m_commandFunctor( fct )
{
}

void Parser::ParseInput( const std::string& input )
{
    std::vector< std::string > tokens;
    boost::split( tokens, input, boost::is_any_of( " ," ) );

    if( !( tokens.empty() ) && m_commandFunctor )
    {
        std::string currentToken = boost::to_upper_copy( tokens.front() );

        if( currentToken == "PLACE" && ( tokens.size() == 4 ) )
        {
            try
            {
                Position position;
                position.SetCoordinates(
                    Coordinates( boost::lexical_cast< int >( tokens.at( 1 ) ), boost::lexical_cast< int >( tokens.at( 2 ) ) ) );
                position.SetDirection( Direction( boost::to_upper_copy( tokens.at( 3 ) ) ) );
                std::shared_ptr< Command > placeCmd{ new PlaceCommand( position ) };
                m_commandFunctor( placeCmd );
            }
            catch( boost::bad_lexical_cast& /*e*/ )
            {
                //cerr or just ignore command?
            }
        }
        else if( currentToken == "MOVE" )
        {
            std::shared_ptr< Command > moveCmd{ new MoveCommand() };
            m_commandFunctor( moveCmd );
        }
        else if( currentToken == "LEFT" )
        {
            Rotation rotation;
            rotation.m_rotation = Rotation::LEFT;
            std::shared_ptr< Command > rotateCmd{ new RotateCommand( rotation ) };
            m_commandFunctor( rotateCmd );
        }
        else if( currentToken == "RIGHT" )
        {
            Rotation rotation;
            rotation.m_rotation = Rotation::RIGHT;
            std::shared_ptr< Command > rotateCmd{ new RotateCommand( rotation ) };
            m_commandFunctor( rotateCmd );
        }
        else if( currentToken == "REPORT" )
        {
            std::shared_ptr< Command > reportCmd{ new ReportCommand() };
            m_commandFunctor( reportCmd );
        }
        else
        {
            //could log invalid command
        }
    }
}

}

