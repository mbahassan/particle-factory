//
// Created by mbahassan on 31-10-23.
//

#ifndef CIRCLECROSSSECTION_H
#define CIRCLECROSSSECTION_H

#include <Shape.h>
#include <cmath>
#include <RenderBondedParticles.h>


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

    /**
     * Function to set-up spheres location
     **/

    void constructor();

    void setName(std::string& name) override;

    void createShape() override;

    void showShape() override ;

    void  writeToFile(const std::string &delimiter );

    virtual std::vector<Sphere> getSphereHandler();

    virtual void populate();

    double getDelta() const ;

    std::vector<double> getXColumn() const;

    std::vector<double> getYColumn() const;

    std::vector<double> getZColumn() const;

    double minZ_ = 0.0;

private:

    bool isOverlap(const Sphere& particle);

    static double distance(const Sphere & sphere1, const Sphere & sphere2);

    int nLayerInR() const ;

    std::string name_ ;

    double circleRadius_ = 0.0;

    double theta_ = 0.0; // in radian

    int failCounter_ = 0;

    int maxCount_ = 2000;

    std::vector<double> xColumn_ {};

    std::vector<double> yColumn_ {};

    std::vector<double> zColumn_ {};

};


#endif // CIRCLECROSSSECTION_H
