//
// Created by iqraa on 17-11-23.
//


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
        create();
    }

    void create()
    {
        for (int i = 0; i < layersZ; ++i)
        {
            setZ(i * (2 * getRadius() - getDelta())) ;
            createShape();
        }
    }


private:
    double nlayerInZ()
    {
        return std::ceil((rodHeight_ + getDelta()) / (2 * getRadius() - getDelta()));
    }

    double rodHeight_ = 0.0;

    int layersZ = 1;
};


int main(int argc, char **argv)
{
    std::string name ="Rod.csv", delim = ",";
    double rodRadius = 0.05;
    double rodHeight = 0.1;
    double rmin = 0.005;
    double delta = 0.000;

    RodBar rod(rodHeight,rodRadius, rmin, delta);

    rod.showShape();
    std::cout << "# of spheres " << rod.sphereHandler.size() << std::endl;

    rod.setName(name);
    rod.writeToFile(delim);
    return 0;
}