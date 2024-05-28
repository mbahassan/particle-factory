//
// Created by iqraa on 17-11-23.
//


#include "RenderShape.h"
#include "CircleSection.h"


class RodBar: public CircleSection
{
public:
    RodBar(double rodHeight, double rodRadius, double rMin, double delta):
            CircleSection(rodRadius, rMin, delta)
    {
        rodHeight_ = rodHeight;

        if (nlayerInZ() >= layersZ)
            layersZ = int(nlayerInZ());

        constructor();
    };

    void constructor()
    {
        createShape();
    }

    void createShape() override
    {
        for (int i = 0; i < layersZ; ++i)
        {
            setZ(i * (2 * getRadius() - getDelta())) ;
            CircleSection::createShape();
        }
    }

    void showShape() override
    {
        RenderShape::renderSphere(sphereHandler);
    }

private:
    double nlayerInZ()
    {
        return std::ceil((rodHeight_ + getDelta()) / (2 * getRadius() - getDelta()));
    }

    double rodHeight_ = 0.0;

    int layersZ = 1;
};


int main(int argc, char **argv) {
    double rod_radius = 0.02;
    double rod_height = 0.05;
    double rmin = 0.005;
    double delta = 0.000;
    RodBar rod( rod_height,rod_radius, rmin, delta);
    rod.showShape();
    std::cout << "# of spheres " << rod.sphereHandler.size() << std::endl;

    std::string name ="RodBar.csv", delim = ",";
    //File csv(name, rod.getXColumn(), rod.getYColumn(), rod.getZColumn(), rod.getRadius());
    //csv.writeToFile(delim);
    return 0;
}