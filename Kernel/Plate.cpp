//
// Created by mbahassan on 18-10-23.
//

#include "Plate.h"

/// Constructors
Plate::Plate(): Shape()
{
    constructor();
}

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

    sphereHandler_ = plate.getSphereHandler();
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
    populate();

    // This is for writing
    file_.setName(name_);

    file_.setXColumn(xColumn_);
    file_.setYColumn(yColumn_);
    file_.setZColumn(zColumn_);

}

/*!
 * @brief Spheres locations which produce the required shape.
 * \return
 * */

void Plate::createShape()
{
    Sphere sphere;
    for (int i = 0; i < nLayersInZ(); ++i)
    {
        for (int j = 0; j < nLayersInY(); ++j)
        {
            for (int k = 0; k < nLayersInX(); ++k)
            {
                sphere.setX(origin_.getX() + k*(2*minRadius_ - delta_)) ;
                sphere.setY(origin_.getY() + j*(2*minRadius_ - delta_)) ;
                sphere.setZ(origin_.getZ() + i*(2*minRadius_ - delta_)) ;
                sphere.setRadius(minRadius_);
                sphereHandler_.push_back(sphere);
            }
        }
    }
}

void Plate::populate()
{
    for (const auto & sphere : sphereHandler_) {
        xColumn_.push_back(sphere.getX());
        yColumn_.push_back(sphere.getY());
        zColumn_.push_back(sphere.getZ());
    }
}

void  Plate::writeToFile(const std::string &delimiter )
{
    file_.setName(name_);
    file_.setSphereHandler(sphereHandler_);
    file_.writeToFile(delimiter);
}

/*!
 * \brief function to render the spheres and show them using VTK.
 * */
void Plate::showShape()
{
    constructor();
    RenderBondedParticles::renderSphere(minRadius_, xColumn_, yColumn_, zColumn_);
}

int Plate::nLayersInX() const
{
    return ceil((lx_ + delta_) / (2 * minRadius_ - delta_));
}

int Plate::nLayersInY() const
{
    return ceil((ly_ + delta_ ) / (2 * minRadius_ - delta_)) ;
}

int Plate::nLayersInZ() const
{
    return ceil((lz_ + delta_) / (2 * minRadius_ - delta_));
}

bool Plate::isParticleOverlap(const Sphere& p)
{
    bool interaction = false;
    for (const Sphere& s : sphereHandler_)
    {
        // calculate the distance between particles
        double d = distance(p, s);

        if (d < (p.getRadius() + s.getRadius() - delta_))
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

double Plate::getDelta() const
{
    return delta_;
}

Point Plate::getOrigin() const
{
    return origin_;
}


/*!
 * \return: sphereHandler_: vectorZ of spheres.
 * */
std::vector<Sphere> Plate::getSphereHandler() const
{
    return sphereHandler_;
}

std::vector<double> Plate::getXColumn() const
{
    return xColumn_;
}

std::vector<double> Plate::getYColumn() const
{
    return yColumn_;
}

std::vector<double> Plate::getZColumn() const
{
    return zColumn_;
}
