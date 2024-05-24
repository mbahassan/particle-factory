//
// Created by iqraa on 26-3-23.
//

#ifndef BONDEDPARTICLEGENERATOR_YDIRECTION_H
#define BONDEDPARTICLEGENERATOR_YDIRECTION_H
#include <vector>
#include <XDirection.h>

class YDirection: public XDirection{
public:
    YDirection();

    YDirection(double particleRadius, double gap, int nParticleInX, int nParticleInY);

    void placeParticles() ;

    std::vector<double> getYPosition() const ;

    int getNinY() const;
private:
    int nInY_ = 0;
    std::vector<double> positionInY_;
};
#endif //BONDEDPARTICLEGENERATOR_YDIRECTION_H
