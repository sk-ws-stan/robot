#ifndef TOYROBOT_ROTATION_H
#define TOYROBOT_ROTATION_H

#include <string>

namespace ToyRobot
{
    struct Rotation
    {
        enum RotationEnum
        {
            LEFT = 0,
            RIGHT = 1,
            INVALID = 2,
        };

        const std::string ToString() const
        {
            return ToString( m_rotation );
        };

        static const std::string ToString( const RotationEnum& rotation )
        {
            std::string returnValue;

            switch( rotation )
            {
                case( LEFT ):
                {
                    returnValue = "LEFT";
                    break;
                }
                case( RIGHT ):
                {
                    returnValue = "RIGHT";
                    break;
                }
                case( INVALID ):
                default:
                {
                    returnValue = "INVALID";
                    break;
                }
            }
            return returnValue;
        };

        RotationEnum m_rotation;
    };
}
#endif

