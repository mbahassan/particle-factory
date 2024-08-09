//
// Created by mbahassan on 18-10-23.
//

#ifndef PLATE_H
#define PLATE_H

//
// Created by mbahassan on 18-10-23.
//


#include <cmath>

#include "Shape.h"
#include "RenderShape.h"
#include "File.h"



class Plate : public Shape
{

public:

    /// Constructors
    Plate();

    Plate(double lx, double ly, double lz, double minRadius,  double delta,
           const Point& origin);

    Plate(const Plate&);

    void setName(std::string& ) override ;

    /// Destructors
    ~Plate();

    /// functions members
    void constructor();

    void createShape() override;

//    void showShape() override ;

    /// Getters
    double getXLength() const;

    double getYLength() const;

    double getZLength() const;

    Point getOrigin() const;


private:

    int nLayersInX() const;

    int nLayersInY() const ;

    int nLayersInZ() const;

    bool isParticleOverlap(const Sphere& p);

    static double distance(const Sphere& sphere1, const Sphere& sphere2);

private:

    double lx_ = 0.0;

    double ly_ = 0.0;

    double lz_ = 0.0;

    File file_ ;
};

#endif //PLATE_H
