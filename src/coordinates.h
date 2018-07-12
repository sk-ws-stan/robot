#ifndef TOYROBOT_COORDINATES_H
#define TOYROBOT_COORDINATES_H

namespace ToyRobot
{
    //contemplated using boost::geometry but decided against, due to added complexity
    class Coordinates
    {
        public:
            Coordinates();
            Coordinates( int x, int y );
            ~Coordinates(){};

            void SetCoordinates( int x, int y );
            void SetX( int x );
            void SetY( int y );
            const int GetX() const;
            const int GetY() const;

        private:
            int m_x;
            int m_y;
    };
}

#endif

