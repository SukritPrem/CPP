#ifndef POINT_H
# define POINT_H
#include "Fixed.hpp"
class Point{
    private:
        Fixed   _x;
        Fixed   _y;
    public:
        Point(void);
        Point(const float x,const float y);
        Point(Point &origin);
        Point & operator=(Point &origin);
        ~Point(void);

        // bool bsp(Point const a, Point const b, Point const c, Point const point);
        float getfloat_x(void) const;
        float getfloat_y(void) const;
        // double area(Point const& a, Point const& b, Point const& c);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
#endif