#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    double totalArea = (a.getfloat_x()     *(b.getfloat_y()     - c.getfloat_y())     + b.getfloat_x()*(c.getfloat_y() - a.getfloat_y()) + c.getfloat_x()*(a.getfloat_y() - b.getfloat_y())) / 2.0;
    double area1     = (point.getfloat_x() *(b.getfloat_y()     - c.getfloat_y())     + b.getfloat_x()*(c.getfloat_y() - point.getfloat_y()) + c.getfloat_x()*(point.getfloat_y() - b.getfloat_y())) / 2.0;
    double area2     = (a.getfloat_x()     *(point.getfloat_y() - c.getfloat_y())     + point.getfloat_x()*(c.getfloat_y() - a.getfloat_y()) + c.getfloat_x()*(a.getfloat_y() - point.getfloat_y())) / 2.0;
    double area3     = (a.getfloat_x()     *(b.getfloat_y()     - point.getfloat_y()) + b.getfloat_x()*(point.getfloat_y() - a.getfloat_y()) + point.getfloat_x()*(a.getfloat_y() - b.getfloat_y())) / 2.0;
    
    return (totalArea == area1 + area2 + area3);
}