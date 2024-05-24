//
// Created by iqraa on 26-3-23.
//

#ifndef BONDEDPARTICLEGENERATOR_XDIRECTION_H
#define BONDEDPARTICLEGENERATOR_XDIRECTION_H
#include <vector>
#include <iostream>
class XDirection{
public:
    XDirection();

    XDirection( double particleRadius, double gap, int nParticleInX);

    void placeParticles();

    int getNinX() const;

    virtual std::vector<double> getXPosition() const;

    double getRadius() const;

    double getGab() const ;

    double getOrigin() const;
private:
    double gap_ = 0;
    double origin_ = 0.0;
    double radius_=0;
    int nInX_ = 0;
    std::vector<double> positionInX_ ;

};
#endif //BONDEDPARTICLEGENERATOR_XDIRECTION_H
