//
// Created by iqraa on 26-3-23.
//

#ifndef WRITECSV_H
#define WRITECSV_H

#include <vector>
#include <iostream>
#include <fstream>
#include "Sphere.h"




class File {

public:
    File() = default ;

    File(const File& file);

    void setHandler(std::vector<Sphere>& sphereHandler);

    void setName(std::string& fname);

    /// Member Functions
    void writeToFile(const std::string &delimiter);

private:

    /// Members Functions
    void write();

    std::string fileName_;

    std::string delimiter_ = ",";

    std::vector<Sphere> handler;

};
#endif //WRITECSV_H
