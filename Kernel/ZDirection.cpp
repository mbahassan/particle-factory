//
// Created by iqraa on 26-3-23.
//
#include <ZDirection.h>


ZDirection::ZDirection() = default;

ZDirection::ZDirection(double particleRadius, double gap, int nParticleInX, int nParticleInY, int nParticleInZ) :
        YDirection(particleRadius, gap, nParticleInX, nParticleInY) {

    nInZ_ = nParticleInZ;

    positionInZ_.resize(getNinX() * getNinY() * nInZ_);

    placeParticles();
}

void ZDirection::placeParticles() {
    if (getGab() != 0.0) {
        for (int k = 0; k < nInZ_; ++k) {
            for (int j = 0; j < getNinY(); ++j) {
                for (int i = 0; i < getNinX(); ++i) {
                    positionInZ_[i + j * getNinY() + k * getNinX() * getNinY()] =
                            getOrigin() + k*getGab() + k * (2*getRadius());
                }
            }
        }
    } else {
        for (int k = 0; k < nInZ_; ++k) {
            for (int j = 0; j < getNinY(); ++j) {
                for (int i = 0; i < getNinX(); ++i) {
                    positionInZ_[i + j * getNinY() + k * getNinX() * getNinY()] =
                            getOrigin() + getGab() + k * (2*getRadius());
                }
            }
        }
    }
}

std::vector<double> ZDirection::getZPosition() const {
    return positionInZ_;
}


