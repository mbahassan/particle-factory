//
// Created by iqraa on 17-11-23.
//

#include "Plate.h"


int main(int argc, char ** argv){
    double rmin = 0.015, delta = 0.00;
    double xl = 1*rmin, yl = 6*rmin, zl = 10*rmin;
    Point orig(0., 0., 0.);
    std::string name = "plate.csv", delim = "t";

    Plate plate(xl,yl,zl,rmin,delta, orig );
    plate.setName(name);

    plate.showShape();
    plate.writeToFile(delim);

    return 0;
}