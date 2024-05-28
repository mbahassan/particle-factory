//
// Created by mbahassan on 17-10-23.
//

#ifndef SPHERE_H
#define SPHERE_H

#include <vector>

#include "Point.h"


class Sphere: public Point
{

public:
    /// Constructors
    Sphere() = default;

    explicit Sphere(double radius);

    Sphere(Point& position, double radius);

    Sphere(double x, double y, double z, double radius);

    /// Destructors
    ~Sphere();

    /// Setters
    void setRadius(double radius);

    /// Getters
    double getRadius() const ;


private:
    double radius_ = 0.0;
};


#endif //SPHERE_H
