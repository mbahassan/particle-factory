//
// Created by iqraa on 19-11-23.
//

#include "CircleSection.h"


int main(int argc, char ** argv){
    double rmin = 0.05, delta = 0.000;
    double R = 3*(rmin*2) + rmin;
    Point orig(0., 0., 0.);
    std::string name = "circleSection.csv", delim = ",";
    CircleSection circleSection(R,rmin, delta);
    circleSection.setName(name);
    circleSection.showShape();
    circleSection.writeToFile(delim);

    return 0;
}