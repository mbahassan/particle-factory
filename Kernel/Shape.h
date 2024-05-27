//
// Created by mbahassan on 15-11-23.
//

#ifndef SHAPE_H
#define SHAPE_H


#include <string>

#include "Sphere.h"
#include "File.h"

class Shape : public Sphere {
public:

    Shape() = default;

    Shape(const Point& origin, const double minRadius, const double delta): Sphere(minRadius)
    {
        origin_ = origin;
        delta_    = delta;
    };

    Shape(const double minRadius, const double delta):Sphere(minRadius)
    {
        delta_    = delta;
    };

    Shape(const Point& origin, const double minRadius, const double delta, std::string& name):Sphere(minRadius)
    {
        origin_ = origin;
        delta_    = delta;
        name_ = name;
    };

    double getDelta() const {return delta_;}

    std::string getName() { return name_; }

    std::vector<Sphere> sphereHandler ;

protected:
    /// function members
    virtual void setName(std::string& name) = 0;

    virtual void createShape() = 0;

    virtual void showShape() = 0;

    Point origin_;

    std::string name_ ;

    double minRadius_ = 0.0;

    double delta_ = 0.0;

    File file ;

};


#endif //SHAPE_H
