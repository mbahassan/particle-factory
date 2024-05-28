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
    nR = nLayerInR();
    constructor();
}

CircleSection::
CircleSection(double circRadius, double rMin, double delta, Point& origin ):
Shape(origin, rMin, delta)
{
    circleRadius = circRadius;
    nR = nLayerInR();
    //
    constructor();
}


CircleSection::
CircleSection(double circRadius, double rMin, double delta ):
        Shape( rMin, delta)
{
    circleRadius = circRadius;
    nR = nLayerInR();

    //
    constructor();
}


CircleSection::
CircleSection(const CircleSection& circleSection):
Shape(circleSection.origin_, circleSection.minRadius_, circleSection.delta_)
{
    circleRadius = circleSection.circleRadius;
    nR = nLayerInR();
    constructor();
}

/**
 * Function members
 **/

void CircleSection::constructor()
{
    createShape();
}

void CircleSection::setName(std::string& name)
{
    name_ = name;
}

void CircleSection::createShape()
{

    Sphere particle;
    particle.setRadius(getRadius());
    //sphereHandler.push_back(particle);

    // loop over the radial layers
    for (int j = 0; j < nR; ++j)
    {
        failCounter = 0;
        theta = 0;
        // update the radius
        double radialPosition = j * (2.0 * getRadius() - getDelta());

        // check if there is overlap
        do {
            double X = radialPosition * std::cos(theta);
            double Y = radialPosition * std::sin(theta);
            particle.setX(X);
            particle.setY(Y);
            particle.setZ(zMin);
            particle.setRadius(getRadius());

            if (isEligible(particle))
            {
                sphereHandler.push_back(particle);
                subHandler.push_back(particle);
            } else
            {
                // increase failCounter
                failCounter += 1;
            }

            // update theta
            theta += M_PI / 100;
            // theta += dTheta;

        } while (failCounter < maxCount);
    }

    // clear the subHandler
    subHandler.clear();
}

void CircleSection::showShape()
{
    RenderShape::renderSphere(sphereHandler);
}


void  CircleSection::writeToFile(const std::string &delimiter )
{
    file.setName(name_);
    file.setHandler(sphereHandler);
    file.writeToFile(delimiter);
}

bool CircleSection::isEligible(const Sphere& particle)
{
    if (subHandler.empty()) return true;

    bool interaction = false;

    for (const Sphere & sphere: subHandler)
    {
        // calculate the distance between particles
        double d = distance(particle, sphere);

        if (d <= dmax && d >= dmin )
        {
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

int CircleSection::nLayerInR()
{
    return  std::ceil((circleRadius- getRadius()) / (2 * getRadius() - getDelta()));
}
