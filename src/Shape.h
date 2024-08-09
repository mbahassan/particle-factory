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

    Shape(const Point& origin, double minRadius, double delta);

    Shape(double minRadius, double delta);

    Shape(const Point& origin, double minRadius, double delta, std::string& name);

    virtual void  writeToFile(const std::string &delimiter );

    double getDelta() const {return delta_;}

    std::string getName() { return name_; }

    std::vector<Sphere> sphereHandler ;

    /*!
     * \brief function to render the spheres and show them using VTK.
     */

    void showShape();

protected:
    /// function members
    virtual void setName(std::string& name) = 0;

    virtual void createShape() = 0;

    Point origin_;

    std::string name_ ;

    double minRadius_ = 0.0;

    double delta_ = 0.0;

    File file ;

};


#endif //SHAPE_H
