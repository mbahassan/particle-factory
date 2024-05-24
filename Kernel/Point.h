//
// Created by mbahassan on 18-10-23.
//

#ifndef ORIGIN_H
#define ORIGIN_H
#include <vector>

class Point
{
public:
    Point() = default;

    Point(double x, double y, double z);

    Point(const Point& );

    /// Overloaded operators
    friend Point operator+(const Point& point1, const Point& point2) {
        Point result;
        result.setX(point1.getX() + point2.getX());
        result.setY(point1.getY() + point2.getY());
        result.setZ(point1.getZ() + point2.getZ());
        return result;
    }

    friend Point operator-(const Point& point1, const Point& point2) {
        Point result;
        result.setX(point1.getX() - point2.getX());
        result.setY(point1.getY() - point2.getY());
        result.setZ(point1.getZ() - point2.getZ());
        return result;
    }

    friend Point operator+(const Point& point, double scalar) {
        Point result;
        result.setX(point.getX() + scalar);
        result.setY(point.getY() + scalar);
        result.setZ(point.getZ() + scalar);
        return result;
    }

    /// Destructor
    ~Point();

    /// Setters
    void setX(double x);

    void setY(double y);

    void setZ(double z);

    ///  Getters
    double getX() const;

    double getY() const;

    double getZ() const;

    Point getPosition() const;

private:
    double x_ = 0.0;
    double y_ = 0.0;
    double z_ = 0.0;
};


#endif //ORIGIN_H
