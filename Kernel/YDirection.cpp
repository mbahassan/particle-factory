//
// Created by iqraa on 26-3-23.
//
#include <YDirection.h>

YDirection::YDirection() = default;

YDirection::YDirection(double particleRadius, double gap, int nParticleInX, int nParticleInY):
        XDirection(particleRadius,gap, nParticleInX){

    nInY_ = nParticleInY;

    positionInY_.resize(nInY_ * getNinX());

    placeParticles();
}

void YDirection::placeParticles()  {
    if (getGab() != 0.0){
        for (int j = 0; j < nInY_; ++j) {
            for (int i = 0; i < getNinX() ; ++i) {
                positionInY_[i + j*nInY_] = getOrigin() + j*getGab() + j*(2*getRadius());
            }
        }
    }else{
        for (int j = 0; j < nInY_; ++j) {
            for (int i = 0; i < getNinX() ; ++i) {
                positionInY_[i + j*nInY_] = getOrigin() + getGab() + j*(2*getRadius());
            }
        }
    }
}

std::vector<double> YDirection::getYPosition() const {
    return positionInY_;
}

int YDirection::getNinY() const{
    return nInY_;
}

