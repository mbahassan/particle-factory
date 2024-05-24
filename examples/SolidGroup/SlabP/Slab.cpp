//
// Created by iqraa on 17-11-23.
//

#include <Plate.h>


int main(int argc, char ** argv){
    double rmin = 0.05, delta = 0.00;
    double xl = 1.0, yl = 0.2, zl = 0.5;
    Point orig(0., 0., 0.);
    std::string name = "plate.csv", delim = ",";
    Plate plate(xl,yl,zl,rmin,delta, orig );
    plate.setName(name);
    plate.showShape();
    plate.writeToFile(delim);

    return 0;
}