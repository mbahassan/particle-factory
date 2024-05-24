//
// Created by mbahassan on 15-11-23.
//

#ifndef SHAPE_H
#define SHAPE_H

#include <Sphere.h>
#include <string>
#include <File.h>

class Shape : public Sphere {
public:

    Shape() = default;

    Shape(const Point& origin, const double minRadius, const double delta)
    {
        origin_ = origin;
        minRadius_= minRadius;
        delta_    = delta;
    };

    Shape(const double minRadius, const double delta)
    {
        minRadius_= minRadius;
        delta_    = delta;
    };

    Shape(const Point& origin, const double minRadius, const double delta, std::string& name)
    {
        origin_ = origin;
        minRadius_= minRadius;
        delta_    = delta;
        name_ = name;
    };

    std::string getName() { return name_; }

protected:
    /// function members
    virtual void setName(std::string& name) = 0;

    virtual void createShape() = 0;

    virtual void showShape() = 0;

    Point origin_;

    std::string name_ ;

    double minRadius_ = 0.0;

    double delta_ = 0.0;

    std::vector<Sphere> sphereHandler_;

    File file_ ;

};


#endif //SHAPE_H
