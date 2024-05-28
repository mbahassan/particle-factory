//
// Created by mbahassan on 31-10-23.
//

#ifndef CIRCLECROSSSECTION_H
#define CIRCLECROSSSECTION_H


#include <cmath>

#include "RenderShape.h"
#include "Shape.h"

/*!
 * Usage:
 *
 *          double radius = 0.2;
 *          double rmin = 0.015;
 *          double delta = 0.01;
 *          CircleCrossSection cs(radius, rmin, delta);
 *          cs.showShape();
 */


class CircleSection : public Shape
{
public:
    /// Constructors
    CircleSection();

    CircleSection(double radius, double rMin, double delta, Point& origin);

    CircleSection(double radius, double rMin, double delta);

    CircleSection(const CircleSection& );

    ~CircleSection() = default;

    /// Member functions
    void constructor();

    void setName(std::string& name) override;

    void createShape() override;

    void showShape() override ;

    void setZ(double z) override { zMin = z; }

private:

    bool isEligible(const Sphere& particle);

    static double distance(const Sphere & sphere1, const Sphere & sphere2);

    int nLayerInR()  ;

    double circleRadius = 0.0;

    double theta = 0.0; // in radian
    double dTheta = 0.0; // in radian

    int failCounter = 0;

    int maxCount = 10;

    int nR = 0;

    double zMin = 0.0;

    std::vector<Sphere> subHandler;
};


#endif // CIRCLECROSSSECTION_H
