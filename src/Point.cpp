//
// Created by mbahassan on 18-10-23.
//

#include "Point.h"

/// Constructors
Point::Point(double x, double y, double z) : x_(x), y_(y), z_(z)
{}

Point::Point(const Point& point)
{
    x_ = point.x_;
    y_ = point.y_;
    z_ = point.z_;
}



/// Destructor
Point::~Point() = default;


/// Setters
void Point::setX(double x)
{
    x_ = x;
};

void Point::setY(double y)
{
    y_ = y;
};

void Point::setZ(double z)
{
    z_ = z;
};



/// Getters
double Point::getX() const { return x_; }

double Point::getY() const { return y_; }

double Point::getZ() const { return z_; }

Point Point::getPosition() const {return {x_, y_, z_}; }

