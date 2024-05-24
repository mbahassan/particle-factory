//
// Created by mbahassan on 31-10-23.
//

#include "CircleSection.h"

/*!
 * Constructors
 * */
CircleSection::
CircleSection(): Shape()
{
    constructor();
}

CircleSection::
CircleSection(double radius, double rMin, double delta, Point& origin ):
Shape(origin, rMin, delta)
{
    circleRadius_ = radius;

    // add the center sphere
    Sphere sphere;
    sphere.setRadius(minRadius_) ;
    sphereHandler_.push_back(sphere);

    //
    constructor();
}


CircleSection::
CircleSection(double radius, double rMin, double delta ):
        Shape( rMin, delta)
{
    circleRadius_ = radius;

    //
    constructor();
}


CircleSection::
CircleSection(const CircleSection & circleCrossSection):
Shape(circleCrossSection.origin_, circleCrossSection.minRadius_,circleCrossSection.delta_)
{
    circleRadius_ = circleCrossSection.circleRadius_;

    //
    constructor();
}

/**
 * Function members
 * */

void CircleSection::constructor()
{
    createShape();
    populate();

    // This is for writing
    file_.setName(name_);

    file_.setXColumn(xColumn_);
    file_.setYColumn(yColumn_);
    file_.setZColumn(zColumn_);

}

void CircleSection::setName(std::string& name)
{
    name_ = name;
}

void CircleSection::createShape()
{

    Sphere particle;
    particle.setRadius(minRadius_) ;
    sphereHandler_.push_back(particle);


    // loop over the radial layers
    for (int j = 0; j < nLayerInR(); ++j) {
        failCounter_ = 0;
        theta_ = 0;
        // update the radius
        double radialPosition = j * (2.0 * minRadius_ - delta_);

        // check if there is overlap
        do {
            particle.setX(radialPosition * std::cos(theta_));
            particle.setY(radialPosition * std::sin(theta_));
            particle.setZ(minZ_);
            particle.setRadius(minRadius_) ;
            theta_ += (2.0 * M_PI) /1000;

            if (!isOverlap(particle)) {
                sphereHandler_.push_back(particle);
            } else {
                // increase failCounter
                failCounter_ += 1;
            }
        } while (failCounter_ < maxCount_);
    }
}

void CircleSection::showShape()
{
    constructor();
    RenderBondedParticles::renderSphere(minRadius_, xColumn_, yColumn_, zColumn_);
}

std::vector<Sphere> CircleSection::getSphereHandler()
{
    return sphereHandler_;
}

void  CircleSection::writeToFile(const std::string &delimiter )
{
    file_.setName(name_);
    file_.setSphereHandler(sphereHandler_);
    file_.writeToFile(delimiter);
}

void CircleSection::populate()
{
    for (auto& sphere : sphereHandler_) {
        xColumn_.push_back(sphere.getX());
        yColumn_.push_back(sphere.getY());
        zColumn_.push_back(sphere.getZ());
    }
}


bool CircleSection::isOverlap(const Sphere& particle)
{
    bool interaction = false;
    if (sphereHandler_.empty()) return interaction;
    for (const Sphere & sphere: sphereHandler_) {
        // calculate the distance between particles
        double d = distance(particle, sphere);

        if (d < (particle.getRadius() + sphere.getRadius() - delta_)) {
            interaction = true;
            break;
        }
    }
    return interaction;
}

double CircleSection::distance(const Sphere &sphere1, const Sphere& sphere2)
{
    Point sphere = sphere2.getPosition() - sphere1.getPosition();
    double xSquare = pow(sphere.getX(), 2.0);
    double ySquare = pow(sphere.getY(), 2.0);
    double zSquare = pow(sphere.getZ(), 2.0);

    return sqrt(xSquare + ySquare + zSquare);
}

int CircleSection::nLayerInR() const
{
    return ceil( (delta_ + circleRadius_) / (2 * minRadius_ - delta_) );
}


double CircleSection::getDelta() const
{
    return delta_;
}

std::vector<double> CircleSection::getXColumn() const
{
    return xColumn_;
};

std::vector<double> CircleSection::getYColumn() const
{
    return yColumn_;
};

std::vector<double> CircleSection::getZColumn() const
{
    return zColumn_;
};