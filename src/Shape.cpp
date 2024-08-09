//
// Created by mbahassan on 15-11-23.
//

#include "Shape.h"
#include "RenderShape.h"


Shape::Shape(const Point& origin, const double minRadius, const double delta):
        Sphere(minRadius)
{
    origin_ = origin;
    delta_    = delta;
};

/*!
 * @brief constructor passing radius of the sphere, and the overlap.
 * */
Shape::Shape(const double minRadius, const double delta):
        Sphere(minRadius)
{
    delta_    = delta;
}

/*!
 * @brief constructor passing origin point, radius of the sphere, overlap and the name.
 * */
Shape::Shape(const Point& origin, const double minRadius, const double delta, std::string& name):
        Sphere(minRadius)
{
    origin_ = origin;
    delta_    = delta;
    name_ = name;
}

/*!
 * Function to render the shape with spheres.
 * */
void Shape::showShape()
{
    RenderShape::renderSphere(sphereHandler);
}


void  Shape::writeToFile(const std::string &delimiter )
{
    file.setName(name_);
    file.setHandler(sphereHandler);
    file.writeToFile(delimiter);
}