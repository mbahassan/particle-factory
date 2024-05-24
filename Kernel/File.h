//
// Created by iqraa on 26-3-23.
//

#ifndef WRITECSV_H
#define WRITECSV_H

#include <vector>
#include <iostream>
#include <fstream>
#include <Sphere.h>


class File: public Sphere{

public:
    File() = default ;

    explicit File(std::string& filename);

    File(const File& filename);

    /// Member Functions
    void writeToFile(const std::string &);

    void setSphereHandler(const std::vector<Sphere>&);

    /// Setters
    void setName(std::string& );

    void setXColumn(std::vector<double>&);

    void setYColumn(std::vector<double>&);

    void setZColumn(std::vector<double>&);

    /// Getters
    std::string getName() const;

    std::vector<double> getXColumn() const;

    std::vector<double> getYColumn() const;

    std::vector<double> getZColumn() const;


private:

    /// Members Functions
    void write();

    std::string fileName_;

    std::string delimiter_ = ",";

    double radius_ = 0;

    std::vector<Sphere> sphereHandler_;

    std::vector<double>  xColumn_ = {0};

    std::vector<double>  yColumn_ = {0};

    std::vector<double>  zColumn_ = {0};

};
#endif //WRITECSV_H
