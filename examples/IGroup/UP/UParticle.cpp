//
// Created by iqraa on 17-11-23.
//
//
// Created by mbahassan on 17-10-23.
//
#include "RenderBondedParticles.h"
#include "File.h"
#include "Plate.h"



class UShape : public Plate {
public:
    explicit UShape(const std::vector<Plate>& plates)
    {
        for ( auto&  plate : plates)
        {
            for (auto& sphere:plate.getSphereHandler())
            {
                sphereHandler_.push_back(sphere);
            }
        }
    }


    void showShape() override
    {
        for (const auto & sphere : sphereHandler_) {
            xColumn_.push_back(sphere.getX());
            yColumn_.push_back(sphere.getY());
            zColumn_.push_back(sphere.getZ());
            radius_ = sphere.getRadius();
        }
        // VTK part
        RenderBondedParticles::renderSphere(radius_, xColumn_, yColumn_, zColumn_);
    }

    void writeToFile(const std::string &delimiter ) override
    {
        file_.setName(name_);
        file_.setSphereHandler(sphereHandler_);
        file_.writeToFile(delimiter);
    }

    void setName (std::string& name) override
    {
        name_ = name;
    }

private:
    std::string name_;

    double  radius_ = 0.0;

    std::vector<double> minRadii_ {};

    std::vector<Sphere> sphereHandler_;

    std::vector<double> xColumn_ {};
    std::vector<double> yColumn_ {};
    std::vector<double> zColumn_ {};

    File file_;
};

int main(int argc, char ** argv){
    std::vector<Plate> plates;

    const double rmin = 0.01, delta = 0.00;
    const double zl = 1.0;
    double xl = 0.5, yl = 0.1;
    Point orig0(0., 0., 0.);
    Plate p0(xl,yl,zl,rmin, delta,orig0);
    plates.push_back(p0);


    Point orig1(0, yl, 0) ;
    xl = 0.1, yl = 0.4;
    Plate p1(xl,yl,zl,rmin, delta,orig1);
    plates.push_back(p1);


    Point orig2(0.4, 0.1, 0) ;
    xl = 0.1, yl = 0.4;
    Plate p2(xl,yl,zl,rmin, delta,orig2);
    plates.push_back(p2);

    std::string name ="UP.csv", delim = ",";
    UShape uShape(plates);
    uShape.setName(name);
    uShape.showShape();
    uShape.writeToFile( delim);

    return 0;
}