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
CircleSection(double circRadius, double rMin, double delta, Point& origin ):
Shape(origin, rMin, delta)
{
    circleRadius = circRadius;

    //
    constructor();
}


CircleSection::
CircleSection(double circRadius, double rMin, double delta ):
        Shape( rMin, delta)
{
    circleRadius = circRadius;
    nLayerInR();
    //
    constructor();
}


CircleSection::
CircleSection(const CircleSection & circleCrossSection):
Shape(circleCrossSection.origin_, circleCrossSection.minRadius_,circleCrossSection.delta_)
{
    circleRadius = circleCrossSection.circleRadius;

    constructor();
}

/**
 * Function members
 * */

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


    // loop over the radial layers
    for (int j = 1; j < nR; ++j)
    {
        Sphere particle;
        particle.setRadius(getRadius());
        sphereHandler.push_back(particle);

        failCounter = 0;
        theta = 0;
        // update the radius
        double radialPosition = j * (2.0 * getRadius() - getDelta());

        // Distance between the centers of adjacent spheres
        double distance = 2 * getRadius() - getDelta();

        // Circumference of the central circle
        double circumference = 2 * M_PI * radialPosition;

        // Number of spheres that fit around the circle
        int N = static_cast<int>(round(circumference / distance));

        // Calculate the angle between each sphere
        double angleIncrement = 2 * M_PI / N;

        // Calculate the positions of the spheres
        for (int i = 0; i < N; ++i) {
            double angle = i * angleIncrement;
            Point pos;
            particle.setX(getRadius() * cos(angle));
            particle.setY(getRadius() * sin(angle));
            particle.setZ(zMin);
            sphereHandler.push_back(particle);
        }

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
        double dm = (particle.getRadius() + sphere.getRadius());
        if (d <= dm + 0.5*getDelta() || d >= dm - 0.5 *getDelta())
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
    return nR = int((circleRadius + getDelta()) / (2 * getRadius() - getDelta()));
}
