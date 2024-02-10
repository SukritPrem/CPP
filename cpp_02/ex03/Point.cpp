        // Point(void);
        // Point(const float x,const float y);
        // Point(Point &origin);
        // Point & operator=(Point &origin);
        // ~Point(void);
#include "Point.hpp"

Point::Point(void)
{
    Fixed a(0);
    Fixed b(0);
    _x = a;
    _y = b;
    // _x.toFloat();
    // std::cout << "Create consturctor" << std::endl;
    // std::cout << _x.getRawBits() << std::endl;
    // std::cout << _y.getRawBits() << std::endl;
}

Point::~Point(void)
{

}

Point & Point::operator=(Point &origin)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &origin) 
    {
        _x = origin._x;
        _y = origin._y;
    }
	return (*this);  
}

Point::Point(const float x,const float y)
{
    Fixed a(x);
    Fixed b(y); 
    _x = a;
    _y = b;
    // std::cout << "setting point" << std::endl;
    // std::cout << _x.getRawBits() << std::endl;
    // std::cout << _y.getRawBits() << std::endl;  
}

Point::Point(Point &origin)
{
	std::cout << "Copy assignment operator called" << std::endl;
    *this = origin;
}

float Point::getfloat_x(void) const
{
    return _x.toFloat();
}
float Point::getfloat_y(void) const
{
    return _y.toFloat();
}

// double Point::area(Point const& a, Point const& b, Point const& c) {
//     return (a.getfloat_x() *(b.getfloat_y() - c.getfloat_y()) + b.getfloat_x()*(c.getfloat_y() - a.getfloat_y()) + c.getfloat_x()*(a.getfloat_y() - b.getfloat_y())) / 2.0;
// }