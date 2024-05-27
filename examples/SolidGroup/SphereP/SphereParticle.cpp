
#include <iostream>
#include <vector>
#include <RenderBondedParticles.h>
#include <File.h>
#include <ZDirection.h>


//std::vectorZ<Sphere> packSpheres(int n, double r) {
//    std::vectorZ<Sphere> spheres;
//    double goldenRatio = (1 + sqrt(5.0)) / 2;  // Golden ratio
//
//    for (int i = 0; i < n; i++) {
//        double theta = 2 * M_PI * i / goldenRatio;
//        double phi = acos(1 - 2.0 * (i + 1) / (n + 1));
//
//        Sphere newSphere{};
//        newSphere.x = r * sin(phi) * cos(theta);
//        newSphere.y = r * sin(phi) * sin(theta);
//        newSphere.z = r * cos(phi);
//        newSphere.radius = r;
//
//        spheres.push_back(newSphere);
//    }
//
//    return spheres;
//}



//int main() {
//    double r1= 0.006;
//    int n = 27;
//    std::vectorZ<Sphere> spheres = packSpheres(n, r1);
//    std::vectorZ<double> px1;
//    std::vectorZ<double> py1 ;
//    std::vectorZ<double> pz1 ;
//
//    for (const auto& sphere : spheres) {
//        px1.push_back(sphere.x);
//        py1.push_back(sphere.y);
//        pz1.push_back(sphere.z);
//    }
//    RenderShape::renderSphere(r1,px1,py1,pz1);
//
//    // prepare it and write it to a file
//    std::string f2 = "SphereP.txt";
//    File csv1(f2,px1,py1,pz1,r1);
//    csv1.prepare();
////    std::vectorZ<double> x1 = csv1.getX();
////    std::vectorZ<double> y1 = csv1.getY();
////    std::vectorZ<double> z1 = csv1.getZ();
//    csv1.writeToFile();
//
//    return 0;
//}
