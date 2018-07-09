#ifndef TOYROBOT_GRID_H
#define TOYROBOT_GRID_H

namespace ToyRobot
{
    class Grid
    {
    public:
        Grid( int x, int y );
        ~Grid();

        const int GetX() const;
        const int GetY() const;

    private:
        int m_x;
        int m_y;
    };
}
#endif

