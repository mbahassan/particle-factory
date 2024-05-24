//
// Created by iqraa on 26-3-23.
//

#ifndef BONDEDPARTICLEGENERATOR_ZDIRECTION_H
#define BONDEDPARTICLEGENERATOR_ZDIRECTION_H
#include <YDirection.h>

class ZDirection: public  YDirection{
public:
    ZDirection() ;

    ZDirection(double particleRadius, double gap, int nParticleInX, int nParticleInY, int nParticleInZ);

    void placeParticles();

    std::vector<double> getZPosition() const;

private:
    int nInZ_ = 0;
    std::vector<double> positionInZ_;
};
#endif //BONDEDPARTICLEGENERATOR_ZDIRECTION_H
