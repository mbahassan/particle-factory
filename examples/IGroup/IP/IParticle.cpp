//
// Created by iqraa on 17-11-23.
//


#include "Plate.h"


class IParticle :public Plate {

public:
    explicit IParticle( std::vector<Plate>& plates )
    {
        for (auto & plate : plates)
        {

            for (auto & s : plate.getSphereHandler())
            {
                sphereHandler_.push_back(s);
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
        RenderShape::renderSphere(radius_, xColumn_, yColumn_, zColumn_);
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

    std::vector<double> xColumn_ ;
    std::vector<double> yColumn_ ;
    std::vector<double> zColumn_ ;

    std::vector<Sphere> sphereHandler_;

    File file_;
};

int main(int argc, char ** argv){
    std::vector<Plate> plates;

    const double rmin = 0.005, delta = 0.00;
    static double Lz = 0.5;

    Point orig0(-0.05, -0.05, 0.);
    double Lx = 0.15, Ly = 0.05;
    std::string name = "p0";
    Plate p0(Lx, Ly, Lz, rmin, delta, orig0);
    plates.push_back(p0);


    Point orig1(0.0, 0.0, 0.0) ;
    Lx = 0.05, Ly = 0.1;
    name = "p1";
    Plate p1(Lx, Ly, Lz, rmin, delta, orig1);
    plates.push_back(p1);

    Point orig2(-0.05, 0.1, 0) ;
    Lx = 0.15, Ly = 0.05;
    name = "p2";
    Plate p2(Lx, Ly, Lz, rmin, delta, orig2);
    plates.push_back(p2);

    name ="IP.csv";
    std::string delim = ",";
    IParticle iParticle( plates);
    iParticle.setName(name);
    iParticle.showShape();

    iParticle.writeToFile( delim);

    return 0;
}