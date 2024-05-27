//
// Created by mbahassan on 18-10-23.
//

#ifndef PLATE_H
#define PLATE_H

//
// Created by mbahassan on 18-10-23.
//

#include <Shape.h>
#include <cmath>
#include <RenderShape.h>
#include <File.h>



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

    void showShape() override ;

    virtual void writeToFile (const std::string &);

    /// Getters
    double getXLength() const;

    double getYLength() const;

    double getZLength() const;

    double getDelta() const;

    Point getOrigin() const;


private:

    void populate();

    int nLayersInX() const;

    int nLayersInY() const ;

    int nLayersInZ() const;

    bool isParticleOverlap(const Sphere& p);

    static double distance(const Sphere& sphere1, const Sphere& sphere2);

private:

    double lx_ = 0.0;

    double ly_ = 0.0;

    double lz_ = 0.0;

    std::vector<double> xColumn_ {};

    std::vector<double> yColumn_ {};

    std::vector<double> zColumn_ {};


    File file_ ;
};

#endif //PLATE_H
