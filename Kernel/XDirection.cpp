//
// Created by iqraa on 26-3-23.
//

/*!
 * This class is for creating a single strip of particles in
 * x-direction
 * @\return
 * std::vectorZ<double> positionInX
 * */
#include <XDirection.h>

XDirection::XDirection() = default;
XDirection::XDirection( double particleRadius, double gap, int nParticleInX):
        nInX_(nParticleInX), radius_(particleRadius), gap_(gap){
    positionInX_.resize(nParticleInX);
    placeParticles();
}

void XDirection::placeParticles() {
    if (gap_ != 0.0){
        for (int i = 0; i < nInX_; ++i) {
            positionInX_[i] = origin_ + i*gap_ + (2*i)*radius_;
        }
    }else{
        for (int i = 0; i < nInX_; ++i) {
            positionInX_[i] = origin_ + gap_ + (2*i)*radius_;
        }
    }
}

int XDirection::getNinX() const {
    return nInX_;
}

std::vector<double> XDirection::getXPosition() const{
    return positionInX_;
}

double XDirection::getRadius() const{
    return radius_;
}

double XDirection::getGab() const {
    return gap_;
}

double XDirection::getOrigin() const {
    return origin_;
}


