//
// Created by iqraa on 26-3-23.
//
#include "File.h"


/// Constructors

File::File(const File& file): fileName_(file.fileName_)
{

}

void File::setHandler(std::vector<Sphere>& sphereHandler)
{
    handler = sphereHandler;
}

void File::setName(std::string& fname)
{
    fileName_ = fname;
}

/// Function Members
void File::writeToFile(const std::string &delimiter )
{
    delimiter_ = delimiter;
    write();
}


void File::write()
{
    std::ofstream outFile;
    outFile.open(fileName_);

    std::string comma = ",";

    if (delimiter_== comma)
    {
        outFile << "x" << "," << "y" << "," << "z" << "," << "radius" << std::endl;
        for (auto & sphere : handler)
        {
            outFile << sphere.getX() << "," << sphere.getY() << "," << sphere.getZ()
                    << "," << sphere.getRadius() << std::endl;
        }
    }
    else
    {
        outFile << "x" << "\t" << "y" << "\t" << "z" << "\t" << "radius" << std::endl;
        for (auto & sphere : handler)
        {
            outFile << sphere.getX() << "," << sphere.getY() << "," << sphere.getZ()
                    << "," << sphere.getRadius() << std::endl;;
        }
    }

    outFile.close();
}


