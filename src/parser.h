#ifndef TOYROBOT_PARSER_H
#define TOYROBOT_PARSER_H

#include "command.h"

#include <functional>
#include <memory>

namespace ToyRobot
{
    typedef std::function< void( std::shared_ptr< Command >& ) > CommandFunctor;

    class Parser
    {
    public:
        Parser( const CommandFunctor& fct );

        void ParseInput( const std::string& input );

    private:
        CommandFunctor m_commandFunctor;
    };
}
#endif

