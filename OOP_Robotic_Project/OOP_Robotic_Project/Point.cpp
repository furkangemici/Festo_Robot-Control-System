#include "Point.h"
#include <cmath>
#include <iostream>
#define M_PI 3.14159265358979323846

Point::Point() : x(0.0), y(0.0) {}


Point::Point(double _x, double _y) : x(_x), y(_y) {}


double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}


void Point::setX(double _x)
{
    this->x = _x;
}


void Point::setY(double _y)
{
    this->y = _y;
}


void Point::getPoint(double& _x, double& _y) const
{
    _x = this->x;
    _y = this->y;
}


void Point::setPoint(double _x, double _y)
{
    this->x = _x;
    this->y = _y;
}


double Point::findDistanceTo(const Point& other) const
{
    return std::sqrt(std::pow(other.x - this->x, 2) + std::pow(other.y - this->y, 2));
}


double Point::findAngleTo(const Point& other) const
{
    return std::atan2(other.y - this->y, other.x - this->x) * (180.0 / M_PI);
}


bool Point::operator==(const Point& other) const
{
    return (this->x == other.x && this->y == other.y);
}


std::ostream& operator<<(std::ostream& out, const Point& point)
{
    out << "(" << point.getX() << ", " << point.getY() << ")";
    return out;
}
