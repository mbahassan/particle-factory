//
// Created by mbahassan on 18-10-23.
//

#include "Plate.h"

/// Constructors

/*! @brief default constructor*/
Plate::Plate(): Shape()
{
    constructor();
}

/*!
 * @brief constructor passing the dimensions and the sphere radius and the overlap and the origin of the shape.
 * */
Plate::Plate( double xLen, double yLen, double zLen, double minRadius,  double delta,
             const Point& origin): Shape(origin + minRadius, minRadius, delta)
{
    lx_= xLen;  ly_=yLen; lz_=zLen;
    constructor();
}

Plate::Plate(const Plate &plate) : Shape (plate)
{
    lx_ = plate.getXLength();
    ly_ = plate.getYLength();
    lz_ = plate.getZLength();

    sphereHandler = plate.sphereHandler;
    minRadius_ = plate.getRadius();
    delta_ = plate.getDelta();
    origin_ = plate.getOrigin() + plate.getRadius();
    constructor();
}

void Plate::setName(std::string& name)
{
    name_ = name;
}

/// Destructors
Plate::~Plate()= default;


/// Functions Members
void Plate::constructor()
{
    createShape();

    // This is for writing
    file_.setName(name_);
}

/*!
 * @brief Spheres locations which produce the required shape.
 * \return
 * */

void Plate::createShape()
{
    Sphere sphere(getRadius());
    for (int i = 0; i < nLayersInZ(); ++i)
    {
        for (int j = 0; j < nLayersInY(); ++j)
        {
            for (int k = 0; k < nLayersInX(); ++k)
            {
                sphere.setX(origin_.getX() + k*(2*getRadius() - getDelta())) ;
                sphere.setY(origin_.getY() + j*(2*getRadius() - getDelta())) ;
                sphere.setZ(origin_.getZ() + i*(2*getRadius() - getDelta())) ;
                sphere.setRadius(getRadius());
                sphereHandler.push_back(sphere);
            }
        }
    }
}


/*!
 * \brief function to render the spheres and show them using VTK.
 */
int Plate::nLayersInX() const
{
    return ceil((lx_ + getDelta()) / (2 * getRadius() - getDelta()));
}

int Plate::nLayersInY() const
{
    return ceil((ly_ + getDelta() ) / (2 * getRadius() - getDelta())) ;
}

int Plate::nLayersInZ() const
{
    return ceil((lz_ + getDelta()) / (2 * getRadius() - getDelta()));
}

bool Plate::isParticleOverlap(const Sphere& p)
{
    bool interaction = false;
    for (const Sphere& s : sphereHandler)
    {
        // calculate the distance between particles
        double d = distance(p, s);

        if (d < (p.getRadius() + s.getRadius() - getDelta()))
        {
            interaction = true;
            break;
        }
    }
    return interaction;
}

double Plate::distance(const Sphere& sphere1, const Sphere& sphere2)
{
    double xSquare = pow((sphere2.getX() - sphere1.getX()), 2.0);
    double ySquare = pow((sphere2.getY() - sphere1.getY()), 2.0);
    double zSquare = pow((sphere2.getZ() - sphere1.getZ()), 2.0);

    return sqrt(xSquare + ySquare + zSquare);
}

/// Getters
double Plate::getXLength() const
{
    return lx_;
}

double Plate::getYLength() const
{
    return ly_;
}

double Plate::getZLength() const
{
    return lz_;
}

Point Plate::getOrigin() const
{
    return origin_;
}
