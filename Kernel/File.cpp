//
// Created by iqraa on 26-3-23.
//
#include <File.h>


/// Constructors
File::File(std::string &fileName)
{
    fileName_ = fileName;
}

File::File(const File& filename): fileName_(filename.fileName_)
{

}


/// Function Members
void File::writeToFile(const std::string &delimiter )
{
    delimiter_ = delimiter;
    write();
}

void File::setSphereHandler(const std::vector<Sphere>& sphereHandler)
{
    sphereHandler_ = sphereHandler;
}

void File::write()
{
    std::ofstream outFile;
    outFile.open(fileName_);

    std::string comma = ",";

    if (delimiter_== comma)
    {
        outFile << "x" << "," << "y" << "," << "z" << "," << "radius" << std::endl;
        for (auto & i : sphereHandler_)
        {
            outFile << i.getX() << "," << i.getY() << "," << i.getZ()
                    << "," << i.getRadius() << std::endl;
        }
    }
    else
    {
        outFile << "x" << "\t" << "y" << "\t" << "z" << "\t" << "radius" << std::endl;
        for (auto & i : sphereHandler_)
        {
            outFile << i.getX() << "," << i.getY() << "," << i.getZ()
                    << "," << i.getRadius() << std::endl;;
        }
    }

    outFile.close();
}


/// Setters
void File::setName(std::string& fileName)
{
    fileName_ = fileName;
}

void File::setXColumn(std::vector<double>& xColumn)
{
    xColumn_ = xColumn;
}

void File::setYColumn(std::vector<double>& yColumn)
{
    yColumn_ = yColumn;
}

void File::setZColumn(std::vector<double>& zColumn)
{
    zColumn_ = zColumn;
}


/// Getters
std::string File::getName() const
{
    return fileName_;
}

std::vector<double> File::getXColumn() const
{
    return xColumn_;
}

std::vector<double> File::getYColumn() const
{
    return yColumn_;
}

std::vector<double> File::getZColumn() const
{
    return zColumn_;
}
