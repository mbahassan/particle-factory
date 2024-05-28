//
// Created by mbahassan on 17-10-23.
//

#include "Sphere.h"

/// Constructors
Sphere::Sphere( double radius) : radius_(radius)
{};

Sphere::Sphere(Point& position, double radius) :
        Point(position) , radius_(radius)
{};

Sphere::Sphere(double x, double y, double z, double radius) :
Point(x, y, z) , radius_(radius)
{};


/// Destructor
Sphere::~Sphere() = default;

/// Setters
void Sphere::setRadius(double radius) { radius_ = radius; }


/// Getters
double Sphere::getRadius() const { return  radius_ ; }
