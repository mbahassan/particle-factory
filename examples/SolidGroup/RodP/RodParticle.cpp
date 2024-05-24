//
// Created by iqraa on 17-11-23.
//


#include <RenderBondedParticles.h>
//#include <File.h>
#include "CircleSection.h"


class RodBar: public CircleSection
{
public:
    RodBar(double rodHeight, double rodRadius, double rMin, double delta):
            CircleSection(rodRadius, rMin, delta)
    {
        rodHeight_ = rodHeight;
    };

    void createShape() override
    {
        for (int i = 0; i < nlayerInZ(); ++i)
        {
            CircleSection::createShape();
            minZ_ = i * (2 * getRadius() - getDelta());
        }
    }

    void showShape() override
    {
        constructor();
        RenderBondedParticles::renderSphere(minRadius_, xColumn_, yColumn_, zColumn_);
    }

private:
    int nlayerInZ()
    {
        return ceil((rodHeight_ + getDelta()) / (2 * getRadius() - getDelta()));
    }

    double rodHeight_ = 0.0;
};


int main(int argc, char **argv) {
    double rod_radius = 0.2;
    double rod_height = 0.8;
    double rmin = 0.005;
    double delta = 0.00;
    RodBar rod( rod_height,rod_radius, rmin, delta);
    rod.showShape();
    std::cout << "# of spheres " << rod.getSphereHandler().size() << std::endl;

    std::string name ="RodBar.csv", delim = ",";
    //File csv(name, rod.getXColumn(), rod.getYColumn(), rod.getZColumn(), rod.getRadius());
    //csv.writeToFile(delim);
    return 0;
}